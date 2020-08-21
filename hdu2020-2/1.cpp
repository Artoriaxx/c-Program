#include <bits/stdc++.h>
#define pb push_back
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

const int N = 2e5 + 50;
int f[N];
vector<int> G[N];
int b[N], id[N];
bool cmp(int x, int y) {
    return b[x] > b[y];
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) {
            in >> b[i];
            id[i] = i;
            f[i] = i;
            G[i].clear();
        }
        sort(id + 1, id + n + 1, cmp);
        for (int i = 1; i <= m; i++) {
            int u, v; in >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int v : G[id[i]]) {
                if (b[v] < b[id[i]]) continue;
                int x = find(id[i]), y = find(v);
                if (x != y) {
                    ans += abs(b[x] - b[y]);
                    if (b[x] < b[y]) f[y] = x;
                    else f[x] = y;
                }
            }
        }
        for (int i = 1; i <= n; i++) if (f[i] == i) ans += b[i];
        printf("%lld\n", ans);
    }
    return 0;
}
