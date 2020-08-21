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

const int N = 55 * 55 * 2;
ll a[N], b[N], c[N];
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct node {
	int u, v, cap;
    ll cost;
    int nxt;
	node() {}
	node (int u, int v, int cap, ll cost, int nxt): u(u), v(v), cap(cap), cost(cost), nxt(nxt) {}
} edge[10010];
int head[N], tot;
void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}
void adde(int u, int v, int w, ll c) {
	edge[tot] = node(u, v, w, c, head[u]);
	head[u] = tot++;
	edge[tot] = node(v, u, 0, -c, head[v]);//回流费用减少
	head[v] = tot++;
}
ll d[N];
int pre[N];
bool vis[N];
bool spfa(int s, int t) {
	queue<int> q;
	memset(d, inf, sizeof(d));
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	d[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].v;
			if (edge[i].cap > 0 && d[v] > d[u] + edge[i].cost) {
				d[v] = d[u] + edge[i].cost;
				pre[v] = i;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return d[t] != inf;
}


int n, m;
void mincostmaxflow(int s, int t) {
    int minn = 1;
    int cnt = 0;
    ll cost = 0;
	while (spfa(s, t)) {
        cnt++;
		for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].v]) {
			edge[i].cap -= minn;
			edge[i ^ 1].cap += minn;
		}
		if (d[t] < 0) break;
		cost += d[t];
        if (cnt == n) {
            printf("%lld\n", cost);
            break;
        }
        printf("%lld ", cost);
	}
}
vector<int> to[N];
int main() {
    int t; in >> t;
    while (t--) {
        in >> n >> m;
        init();
        for (int i = 1; i <= n; i++) {
            in >> a[i] >> b[i] >> c[i];
            to[i].clear();
        }
        vector<int> lis;
        for (int i = 1; i <= n; i++) {
            int mn = -b[i] / (2 * a[i]);
            adde(0, i, 1, 0);
            int p = min(mn, m);
            p = max(p, 1);
            int l = p, r = p + 1;
            for (int j = 1; j <= n; j++) {
                if (l < 1) {
                    lis.push_back(r);
                    to[i].push_back(r++);
                }
                else if (r > m) {
                    lis.push_back(l);
                    to[i].push_back(l--);
                }
                else {
                    if (a[i] * l * l + b[i] * l + c[i] > a[i] * r * r + b[i] * r + c[i]) {
                        lis.push_back(r);
                        to[i].push_back(r++);
                    }
                    else {
                        lis.push_back(l);
                        to[i].push_back(l--);
                    }
                }
            }
            // tle
            // for (int j = p; j >= p - n && j >= 1; j--) {
            //     to[i].push_back(j);
            //     lis.push_back(j);
            // }
            // for (int j = p + 1; j <= p + n + 1 && j <= m; j++) {
            //     to[i].push_back(j);
            //     lis.push_back(j);
            // }
        }
        sort(lis.begin(), lis.end());
        lis.erase(unique(lis.begin(), lis.end()), lis.end());
        for (int i = 1; i <= n; i++) {
            for (int j : to[i]) {
                int x = lower_bound(lis.begin(), lis.end(), j) - lis.begin() + 1;
                adde(i, x + n, 1, a[i] * j * j + b[i] * j + c[i]);
            }
        }
        for (int i = 1; i <= lis.size(); i++) {
            adde(i + n, n + lis.size() + 1, 1, 0);
        }
        mincostmaxflow(0, n + lis.size() + 1);
    }
    return 0;
}
