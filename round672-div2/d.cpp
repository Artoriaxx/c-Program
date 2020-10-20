#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 6e5 + 50;
int lis[N<<1];
struct node {
    int l, r;
    bool operator < (const node &b) const {
        if (l == b.l) return r < b.r;
        return l < b.l;
    }
} a[N];
int sum[N<<2];
int add[N<<2];
#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
void pushdown(int o, int l, int r) {
    if (add[o]) {
        add[ls] += add[o];
        add[rs] += add[o];
        sum[ls] += add[o] * (mid - l + 1);
        sum[rs] += add[o] * (r - mid);
        add[o] = 0;
    }
}
void pushup(int o) {
    sum[o] = sum[ls] + sum[rs];
}
void update(int o, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        sum[o] += v * (r - l + 1);
        add[o] += v;
        return;
    }
    pushdown(o, l, r);
    if (ql <= mid) update(ls, l, mid, ql, qr, v);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, v);
    pushup(o);
}
int query(int o, int l, int r, int x) {
    if (l == r) return sum[o];
    pushdown(o, l, r);
    if (x <= mid) return query(ls, l, mid, x);
    else return query(rs, mid + 1, r, x);
}
const int p = 998244353;
int fac[N], inv[N];
int C(int n, int m) {
    if (m > n) return 0;
    return 1ll * fac[n] * inv[n - m] % p * inv[m] % p;
}
int qpow(int a, int b) {
    int ans = 1; 
    while (b) {
        if (b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}
int main() {
    fac[0] = 1;

    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % p;
    }
    inv[N-1] = qpow(fac[N-1], p - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
    }
    int n, k; in >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        in >> a[i].l >> a[i].r;
        lis[++cnt] = a[i].l;
        lis[++cnt] = a[i].r;
    }
    sort(lis + 1, lis + cnt + 1);
    int m = unique(lis + 1, lis + cnt + 1) - lis - 1;
    for (int i = 1; i <= n; i++) {
        a[i].l = lower_bound(lis + 1, lis + m + 1, a[i].l) - lis;
        a[i].r = lower_bound(lis + 1, lis + m + 1, a[i].r) - lis;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        ans = (ans - C(query(1, 1, m, i), k) + p) % p;
        while (a[j].l == i) {
            update(1, 1, m, a[j].l, a[j].r, 1);
            j++;
        }
        ans = (ans + C(query(1, 1, m, i), k)) % p;
    }
    printf("%d\n", ans);
    return 0;
}
