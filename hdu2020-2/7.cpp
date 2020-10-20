#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e4 + 5;
struct node {
    int v, a, b;
    node (int v = 0, int a = 0, int b = 0): v(v), a(a), b(b) {}
};
vector<node> G[N];
ll f[N][21];
ll t[21];
int sz[N];
int n, k;
void dfs(int u, int fa, ll len) {
    sz[u] = 1; f[u][0] = 0, f[u][1] = len + 1;
    for (auto nx : G[u]) {
        if (nx.v == fa) continue;
        dfs(nx.v, u, len);
        for (int i = 0; i <= k; i++) t[i] = len + 1;
        for (int i = 0; i <= sz[u] && i <= k; i++) {
            for (int j = 0; i + j <= k && j <= sz[nx.v]; j++) {
                if (f[u][i] + f[nx.v][j] + nx.a <= len) t[i+j+1] = min(t[i+j+1], max(f[u][i], f[nx.v][j] + nx.a));
                if (f[u][i] + f[nx.v][j] + nx.b <= len) t[i+j] = min(t[i+j], max(f[u][i], f[nx.v][j] + nx.b));
            }
        }
        for (int i = 0; i <= k; i++) f[u][i] = t[i];
        sz[u] += sz[nx.v];
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        in >> n >> k;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v, a, b; in >> u >> v >> a >> b;
            G[u].push_back(node(v, a, b));
            G[v].push_back(node(u, a, b));
        }
        ll l = 1, r = 1e14;
        ll ans = 1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            dfs(1, 0, mid);
            if (f[1][k] <= mid) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
