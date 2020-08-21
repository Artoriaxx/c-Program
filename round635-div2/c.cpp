#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ios {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x) {
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
vector<int> G[N];
int dep[N];
int a[N];
int vis[N];
int sz[N];
void dfs(int u, int f) {
    dep[u] = dep[f] + 1; sz[u] = 1;
    for (auto v : G[u]) if (v != f) dfs(v, u), sz[u] += sz[v];
}
bool cmp(int a, int b) {
    return dep[a] - sz[a] > dep[b] - sz[b];
}
ll ans;

int main() {
    int n, k; in >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) a[i] = i;
    dep[0] = 0;
    dfs(1, 0);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= k; i++) {
        ans += dep[a[i]] - sz[a[i]];
    }
    printf("%lld\n", ans);
    return 0;
}
