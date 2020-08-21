#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_lEN = 1 << 18 | 1;
        static char buf[IN_lEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_lEN, stdin)), s == t ? -1 : *s++;
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
int cnt = 0;
// struct seg {
//     int l, r, sze, sum;
//     void clear() {
//         l = r = sze = sum = 0;
//     }
// } t[N * 20];
// inline void pushup(int o) {
//     t[o].sze = t[t[o].l].sze + t[t[o].r].sze;
// }
// inline void change(int &o, int l, int r, int x, int v) {
//     if (!o) o = ++cnt, t[o].clear();
//     if (l == r) {
//         t[o].sum += v;
//         t[o].sze = t[o].sum > 0 ? 1 : 0;
//         return;
//     }
//     if (x <= mid) change(t[o].l, l, mid, x, v);
//     else change(t[o].r, mid + 1, r, x, v);
//     pushup(o);
// }
// inline int getAns(int &o, int l, int r) {
//     if (!o) o = ++cnt, t[o].clear();
//     if (l == r) return l;
//     if (t[t[o].l].sze == mid - l + 1) return getAns(t[o].r, mid + 1, r);
//     else return getAns(t[o].l, l, mid);
// }

struct BIT {
    int d[N], mp[N], sze;
    void init(int n) {
        sze = n;
        for (int i = 1; i <= n; i++) d[i] = mp[i] = 0;
    }
    void change(int x, int v) {
        mp[x] += v;
        if ((mp[x] == 1 && v == 1) || (mp[x] == 0 && v == -1)) {
            for (int i = x; i <= sze; i += i & -i) d[i] += v;
        }
    }
    int get(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += d[i];
        return ans;
    }
    int getAns() {
        int l = 1, r = sze, ans = 0;
        while (l <= r) {
            if (get(mid) == mid) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
} bit[405];
int a[N];
int d[N];
int vis[N];
vector<int> G[N], g[N];
int rt[N];

int main() {
    int tc; in >> tc;
    while (tc--) {
        cnt = 0;
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) {
            in >> a[i]; a[i]++;
            d[i] = vis[i] = rt[i] = 0;
            G[i].clear(); g[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v; in >> u >> v;
            G[u].push_back(v); G[v].push_back(u);
            d[u]++; d[v]++;
        }
        int sze = sqrt(n) + 1;
        for (int i = 1; i <= n; i++) {
            if (d[i] > sze) vis[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                bit[rt[i] = ++cnt].init(d[i]);
                for (int v : G[i]) {
                    g[v].push_back(i);
                    if (a[v] <= d[i]) bit[rt[i]].change(a[v], 1);
                }
            }
        }
        int q; in >> q;
        while (q--) {
            int op; in >> op;
            if (op == 1) {
                int x, v; in >> x >> v;
                v++;
                for (int vv : g[x]) {
                    if (a[x] <= d[vv]) bit[rt[vv]].change(a[x], -1);
                    if (v <= d[vv]) bit[rt[vv]].change(v, 1);
                }
                a[x] = v;
            }
            else {
                int x; in >> x;
                if (vis[x]) printf("%d\n", bit[rt[x]].getAns());
                else {
                    set<int> tmp;
                    for (auto v : G[x]) tmp.insert(a[v] - 1);
                    int ans = 0;
                    for (int i : tmp) {
                        if (ans == i) ans++;
                        else break;
                    }
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}
