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

const int N = 5e5 + 50;
vector<int> G[N];
ll sz[N];
ll ans = 0;
ll res = 0;
void dfs(int u, int fa) {
    sz[u] = 1;
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void dfs1(int u, int fa, ll val, ll dep) {
    res = max(res, ans + dep * sz[1] - val);
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs1(v, u, val + sz[v], dep + 1);
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        res = ans = 0;
        for (int i = 1; i <= n; i++) G[i].clear(), sz[i] = 0;
        for (int i = 2; i <= n; i++) {
            int x; in >> x;
            G[i].push_back(x);
            G[x].push_back(i);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) ans += sz[i];
        dfs1(1, 0, sz[1], 1);
        printf("%lld\n", res);
    }
    return 0;
}
