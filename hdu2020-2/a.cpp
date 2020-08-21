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

const int N = 1e5 + 50;
vector<int> G[N];
int b[N];
int p;
int mx;
ll ans = 0;
int f[N];
int vis[N], vis1[N];
void dfs1(int u) {
    vis1[u] = 1;
    if (b[u] > mx) {
        mx = b[u];
        p = u;
    }
    for (auto v : G[u]) {
        if (!vis1[v]) dfs1(v);
    }
}
void dfs(int u) {
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto v : G[now]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
            f[v] = min(b[v], max(f[v], f[now]));
        }
    }
}
int a[N];
bool cmp(int x, int y) {
    return b[x] > b[y];
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int mn[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, m;
        ans = 0;
        in >> n >> m;
        for (int i = 1; i <= n; i++) in >> b[i];
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            vis[i] = 0;
            vis1[i] = 0;
            f[i] = i;
            a[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            in >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            mn[i] = b[i];
        }
        for (int i = 1; i <= n; i++) {
            int now = a[i];
            for (auto v : G[now]) {
                if (b[v] <= b[now]) continue;
                else {
                    int x = find(now);
                    int y = find(v);
                    if (x != y) {
                        ans += abs(mn[y] - mn[x]);
                        f[y] = x;
                        mn[x] = min(mn[x], mn[y]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int x = find(i);
            if (!vis[x]) {
                ans += mn[x];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
