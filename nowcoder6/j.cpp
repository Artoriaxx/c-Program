#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 1e5 + 50;

#define mid (l+r>>1)
#define ls (o<<1)
#define rs (o<<1|1)
int sum[N << 2];
void build(int o, int l, int r) {
    if (l == r) { sum[o] = 1; return; }
    build(ls, l, mid); build(rs, mid + 1, r);
    sum[o] = sum[ls] + sum[rs];
}
void update(int o, int l, int r, int x, int v) {
    if (l == r) { sum[o] += v; return; }
    if (x <= mid) update(ls, l, mid, x, v);
    else update(rs, mid + 1, r, x, v);
    sum[o] = sum[ls] + sum[rs];
}
int query(int o, int l, int r, int v) {
    if (l == r) { return l; }
    if (sum[ls] >= v) return query(ls, l, mid, v);
    else return query(rs, mid + 1, r, v - sum[ls]);
}

int a[N];
int n;
void cals(int k) {
    build(1, 1, n);
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        pos = (pos - 1 + k - 1) % (n - i + 1) + 1;
        a[i] = query(1, 1, n, pos);
        update(1, 1, n, a[i], -1);
    }
}
int ans[N];
int base[N];
int tmp[N];
void getAns(int x) {
    for (int i = 1; i <= n; i++) base[i] = a[i];
    while (x) {
        if (x & 1) {
            for (int i = 1; i <= n; i++) tmp[i] = ans[i];
            for (int i = 1; i <= n; i++) ans[i] = tmp[base[i]];
        }
        for (int i = 1; i <= n; i++) tmp[i] = base[i];
        for (int i = 1; i <= n; i++) base[i] = tmp[base[i]];
        x >>= 1;
    }
    
}
int main() {
    int m; in >> n >> m;
    for (int i = 1; i <= n; i++) ans[i] = i;
    while (m--) {
        int k, x;
        in >> k >> x;
        cals(k);
        getAns(x);  
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}
