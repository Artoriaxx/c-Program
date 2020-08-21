#include <bits/stdc++.h>
#define pii pair<long long, int>
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
    int v; ll w;
    node(int v = 0, ll w = 0): v(v), w(w) {}
};
vector<node> G[N];
const ll inf = 1e18;
char dir[N];
ll d[N];
int vis[N];
int n;
int cnt;
void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii> > q;
	fill (d, d + 2 * n + 2, inf);
	fill (vis, vis + 2 * n + 1, false);
	d[s] = 0;
	q.push(make_pair(d[s], s));
	while (!q.empty()) {
		pii now = q.top(); q.pop();
		int u = now.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			ll w = G[u][i].w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(make_pair(d[v], v));
			}
		}
	}
}
struct chai {
    int l, r;
    chai(int l = 0, int r = 0): l(l), r(r) {}
} point[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        cnt = 0;
        int m, s, t; ll x;
        scanf("%d%d%d%d%lld", &n, &m, &s, &t, &x);
        scanf("%s", dir + 1);
        for (int i = 1; i <= n; i++) {
            if (dir[i] == 'M') {
                cnt++;
                point[i] = chai(i, i + cnt);
            }
        }
        for (int i = 1; i <= 2 * n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v; ll w;
            scanf("%d%d%lld", &u, &v, &w);
            if ((dir[u] == 'L' && dir[v] == 'R') || (dir[u] == 'R' && dir[v] == 'L')) {
                G[u].push_back(node(v, w + x));
                G[v].push_back(node(u, w + x));
            }
            else if (dir[u] == 'M' && dir[v] == 'M') {
                G[point[u].l].push_back(node(point[v].r, w + x));
                G[point[u].l].push_back(node(point[v].l, w));
                G[point[u].r].push_back(node(point[v].r, w));
                G[point[u].r].push_back(node(point[v].l, w + x));
                G[point[v].l].push_back(node(point[u].r, w + x));
                G[point[v].l].push_back(node(point[u].l, w));
                G[point[v].r].push_back(node(point[u].r, w));
                G[point[v].r].push_back(node(point[u].l, w + x));
            }
            else if (dir[u] == 'M' && dir[v] == 'L') {
                G[point[u].l].push_back(node(v, w));
                G[point[u].r].push_back(node(v, w + x));
                G[v].push_back(node(point[u].l, w));
                G[v].push_back(node(point[u].r, w + x));
            }
            else if (dir[u] == 'L' && dir[v] == 'M') {
                G[point[v].l].push_back(node(u, w));
                G[point[v].r].push_back(node(u, w + x));
                G[u].push_back(node(point[v].l, w));
                G[u].push_back(node(point[v].r, w + x));
            }
            else if (dir[u] == 'M' && dir[v] == 'R') {
                G[point[u].l].push_back(node(v, w + x));
                G[point[u].r].push_back(node(v, w));
                G[v].push_back(node(point[u].l, w + x));
                G[v].push_back(node(point[u].r, w));
            }
            else if (dir[u] == 'R' && dir[v] == 'M') {
                G[point[v].l].push_back(node(u, w + x));
                G[point[v].r].push_back(node(u, w));
                G[u].push_back(node(point[v].l, w + x));
                G[u].push_back(node(point[v].r, w));
            }
        }
        if (dir[s] == 'M') {
            G[0].push_back(node(point[s].l, 0));
            G[0].push_back(node(point[s].r, 0));
        }
        else {
            G[0].push_back(node(s, 0));
        }
        if (dir[t] == 'M') {
            cnt++;
            G[point[t].l].push_back(node(n + cnt, 0));
            G[point[t].r].push_back(node(n + cnt, 0));
        }
        else {
            cnt++;
            G[t].push_back(node(n + cnt, 0));
        }
        dijkstra(0);
        printf("%lld\n", d[n + cnt]);
    }
    return 0;
}
