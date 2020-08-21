#include <bits/stdc++.h>
#define pli pair<long long, int>
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

const int N = 2550;
struct node {
    int v; ll w;
    node (int v = 0, ll w = 0): v(v), w(w) {}
};
vector<node> G[N];
bool vis[N];
ll d[N];
int n, m;
const ll inf = 0x7fffffffffffffff;
void dijkstra(int u) {
    fill(d + 1, d + n + 1, inf);
    memset(vis, false, sizeof(vis));
    d[u] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > q;
    q.push(pli(d[u], u));
    while (!q.empty()) {
        pli now = q.top();
        q.pop();
        int uu = now.second;
        if (vis[uu]) continue;
        vis[uu] = 1;
        for (auto nx : G[uu]) {
            int v = nx.v;
            ll w = nx.w;
            if (d[v] > d[uu] + w) {
                d[v] = d[uu] + w;
                q.push(pli(d[v], v));
            }
        }
    }

}
int main() {
    int s, t;
    while (~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v; ll w;
            scanf("%d%d%lld", &u, &v, &w);
            G[u].push_back(node(v, w));
            G[v].push_back(node(u, w));
        }
        dijkstra(s);
        printf("%lld\n", d[t]);
    }
    
    return 0;
}
