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
#define pli pair<long long, int>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
const int N = 1e5 + 50;
int mn[N << 2], addv[N << 2];
int b[N];
void pushup(int o) {
    mn[o] = min(mn[lc], mn[rc]);
}
void build(int o, int l, int r) {
    if (l == r) {
        mn[o] = b[l];
        addv[o] = 0;
        return;
    }
    addv[o] = 0;
    build(lc, l, mid); build(rc, mid + 1, r);
    pushup(o);
}
void pushdown(int o) {
    if (addv[o]) {
        mn[lc] -= addv[o];
        mn[rc] -= addv[o];
        addv[lc] += addv[o];
        addv[rc] += addv[o];
        addv[o] = 0;
    }
}
void change(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        mn[o]--;
        addv[o]++;
        return;
    }
    pushdown(o);
    if (ql <= mid) change(lc, l, mid, ql, qr);
    if (qr > mid) change(rc, mid + 1, r, ql, qr);
    pushup(o);
}
int query(int o, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
        return mn[o];
    }
    pushdown(o);
    if (qr <= mid) return query(lc, l, mid, ql, qr);
    else if (ql > mid) return query(rc, mid + 1, r, ql, qr);
    else return min(query(lc, l, mid, ql, mid), query(rc, mid + 1, r, mid + 1, qr));
}

ll a[N];
void myitoa(__int128 v, char* s)
{
    char temp;
    int i=0, j;

    while(v >0) {
        s[i++] = v % 10 + '0';
        v /= 10;
    }
    s[i] = '\0';

    j=0;
    i--;
    while(j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}
inline void write(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    int t; in >> t;
    int cse = 0;
    while (t--) {
        int n; in >> n;
        memset(mn, 0, sizeof(mn));
        memset(addv, 0, sizeof(addv));
        priority_queue<pli> q;
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
            a[i] += a[i - 1];
            q.push(pli(a[i], i));
        }
        for (int i = 1; i <= n; i++) in >> b[i];
        build(1, 1, n);
        __int128 ans = 0;
        while (!q.empty()) {
            pli now = q.top();
            q.pop();
            if (query(1, 1, n, 1, now.second) <= 0) continue;
            ans += now.first;
            change(1, 1, n, 1, now.second);
            if (query(1, 1, n, 1, now.second) > 0) q.push(now);
        }
        printf("Case #%d: %d ", ++cse, b[1]);
        write(ans);
        puts("");
    }
    return 0;
}