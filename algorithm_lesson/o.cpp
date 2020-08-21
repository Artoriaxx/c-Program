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

const int N = 2050;
struct node {
    int v; ll w;
    node (int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
int sz[N];
ll f[N][N];
int n, k;
void dfs(int u, int fa) {
    f[u][0] = f[u][1] = 0;
    sz[u] = 1;
    for (auto nx : G[u]) {
        if (nx.v == fa) continue;
        dfs(nx.v, u);
        sz[u] += sz[nx.v];
        int m = min(sz[u], k);
        for (int i = m; i >= 0; i--) {
            for (int j = 0; j <= sz[nx.v] && j <= i; j++) {
                ll ans = f[nx.v][j] + nx.w * ((k - j) * j + (sz[nx.v] - j) * (n - k - sz[nx.v] + j));
                f[u][i] = max(f[u][i], f[u][i - j] + ans);
            }
        }
    }
}
int main() {
    in >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; ll w;
        in >> u >> v >> w;
        G[u].push_back(node(v, w));
        G[v].push_back(node(u, w));
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = -1e18;
    dfs(1, 0);
    printf("%lld\n", f[1][k]);
    return 0;
}
