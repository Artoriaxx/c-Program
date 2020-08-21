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

const int N = 505;
int c[N], h1[N], h2[N];
struct node {
    int v, w;
    node(int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
double f1[N][N], f2[N][N];
int vis[N][N];
void work(int u, int w) {
    if (vis[u][w]) return;
    f1[u][w] = h1[u];
    f2[u][w] = h2[u];
    vis[u][w] = 1;
    double sum1 = 0, sum2 = 0;
    int cnt = 0;
    for (auto v : G[u]) {
        if (w - v.w - c[v.v] >= 0) {
            work(v.v, w - v.w - c[v.v]);
            cnt++;
            sum1 += f1[v.v][w - v.w - c[v.v]];
            sum2 += f2[v.v][w - v.w - c[v.v]];
        }
    }
    if (cnt) f1[u][w] += 1.0 * sum1 / cnt;
    if (cnt) f2[u][w] += 1.0 * sum2 / cnt;
}
int main() {
    int n, m, k;
    in >> n >> m >> k;
    for (int i = 1; i <= n; i++) in >> c[i] >> h1[i] >> h2[i];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        G[u].push_back(node(v, w));
        G[v].push_back(node(u, w));
    }
    double ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        if (k >= c[i]) {
            work(i, k - c[i]);
            ans1 += f1[i][k - c[i]];
            ans2 += f2[i][k - c[i]];
        }
    }
    printf("%.5f %.5f\n", 1.0 * ans1 / n, 1.0 * ans2 / n);
    return 0;
}
