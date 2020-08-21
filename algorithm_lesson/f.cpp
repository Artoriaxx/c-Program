#include <bits/stdc++.h>
#define pi pair<int, int>
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

const int N = 1050;

struct node {
    int v, w;
    node (int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
int vis[N];
int n, m, c;
const int inf = 0x3f3f3f3f;
void dijkstra(int s, int d[]) {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	fill(d + 1, d + m + 1, inf);
	d[s] = 0;
	fill(vis, vis + m + 1, false);
	q.push(make_pair(d[s], s));
	while (!q.empty()) {
		pi now = q.top(); q.pop();
		int u = now.second;
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : G[u]) {
            if (d[v.v] > d[u] + v.w) {
                d[v.v] = d[u] + v.w;
                q.push(make_pair(d[v.v], v.v));
            }
        }
	}
}
int d[N][N];
int a[N];
int main() {
    in >> n >> m >> c;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        in >> u >> v >> w;
        G[u].push_back(node(v, w));
        G[v].push_back(node(u, w));
    }
    for (int i = 1; i <= n; i++) 
        dijkstra(a[i], d[a[i]]);
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) {
        ll tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp += d[a[j]][i];
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
