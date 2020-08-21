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
int p[N];
int d1[N], d2[N], d3[N];
int vis[N];
ll pre[N];
vector<int> G[N];
int n, m, a, b, c;
void bfs(int u, int d[]) {
    for (int i = 1; i <= n; i++) vis[i] = 0;
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for (auto v : G[now]) {
            if (vis[v]) continue;
            d[v] = d[now] + 1;
            q.push(v);
            vis[v] = 1;
        }
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        
        in >> n >> m >> a >> b >> c;
        for (int i = 1; i <= n; i++) G[i].clear(), d1[i] = d2[i] = d3[i] = 0;
        for (int i = 1; i <= m; i++) in >> p[i];
        for (int i = 1; i <= m; i++) {
            int u, v;
            in >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bfs(a, d1);
        bfs(b, d2);
        bfs(c, d3);
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= m; i++) pre[i] = pre[i - 1] + p[i];
        ll res = 1e18;
        for (int i = 1; i <= n; i++) {
            if (d1[i] + d2[i] + d3[i] > m) continue;
            res = min(res, pre[d1[i] + d2[i] + d3[i]] + pre[d2[i]]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
