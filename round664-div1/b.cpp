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

const int N = 2e5 + 50;
struct node {
    int v, w;
    node (int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
ll hs[N];
ll val[100][100];
int ans = 0;
int k;
int c[N];
ll res = 0;
void dfs(int dep) {
    if (dep > k) {
        ll now = 0;
        for (int i = 1; i <= k; i++) {
            now += val[i][c[i]];
        }
        if (now == res) ans++;
        return;
    }
    for (int i = 1; i <= dep; i++) {
        c[dep] = i;
        dfs(dep + 1);
    }
}
bool cmp(node a, node b) {
    return a.w < b.w;
}
int main() {
    int n, m; in >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        G[u].push_back(node(v, w));
    }
    for (int i = 1; i <= n; i++) {
        hs[i] = rand();
        res += hs[i];
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        sort(G[i].begin(), G[i].end(), cmp);
        for (node v : G[i]) {
            val[G[i].size()][++cnt] += hs[v.v];
        }
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
