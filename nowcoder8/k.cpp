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

const int N = 1e5 + 50;


ll a[N];
int b[N];

/********************************/
ll st[N][20]; int lg2[N];
void ST(int n) {
    for (int i = 1; i <= n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; (i + (1 << j) - 1) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
}

ll rmq(int l, int r) {
    if (l > r)
        return 0;
    else {
        int x = lg2[r - l + 1];
        return max(st[l][x], st[r - (1 << x) + 1][x]);
    }
}
/********************************/


/********************************/
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
int mn[N << 2], addv[N << 2];
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
/********************************/

int main() {
    int t; in >> t;
    int cse = 0;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i++) in >> b[i];
        build(1, 1, n);
        ST(n);
        ll ans = 0;
        for (int i = 1; i <= b[1]; i++) {
            int l = 1, r = n;
            int pos = 1;
            while (l <= r) {
                if (query(1, 1, n, 1, mid) > 0) {
                    pos = max(pos, mid);
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            l = 1, r = pos;
            ll mx = rmq(l, r);
            ans += mx;
            int p2 = pos;
            while (l <= r) {
                if (rmq(1, mid) == mx) {
                    p2 = min(p2, mid);
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            change(1, 1, n, 1, p2);
        }
        printf("Case #%d: %d %lld\n", ++cse, b[1], ans);
    }
    return 0;
}
