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

const int N = 350;
ll G[N][N];
int a[N<<1];
ll f[N<<1][N];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n, m, k; in >> n >> m >> k;
    memset(G, inf, sizeof(G));
    for (int i = 1; i <= m; i++) {
        int u, v; ll w; in >> u >> v >> w;
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[v][u], w);
    }
    for (int i = 1; i <= n; i++) G[i][i] = 0;
    k *= 2;
    for (int i = 1; i <= k; i++) in >> a[i];
    a[0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    memset(f, inf, sizeof(f));
    f[0][1] = 0;
    for (int i = 1; i <= k; i++) {
        for (int p = 1; p <= n; p++) {
            if (f[i-1][p] != inf) f[i][p] = min(f[i][p], f[i-1][p] + G[a[i-1]][a[i]]);
            for (int q = 1; q <= n; q++) {
                f[i][q] = min(f[i][q], f[i-1][p] + G[a[i-1]][q] + G[p][a[i]]);
                f[i][q] = min(f[i][q], f[i-1][p] + G[a[i-1]][q] + G[q][a[i]]);
                f[i][q] = min(f[i][q], f[i-1][p] + G[p][q] + G[q][a[i]]);
            }
        }
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++) ans = min(ans, f[k][i]);
    printf("%lld\n", ans);
    return 0;
}
