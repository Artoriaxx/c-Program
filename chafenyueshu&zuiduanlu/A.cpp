#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 500005;
struct node {
    int v, w;
    node (int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
int dis[N];
int vis[N];
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int l = inf, r = 0;
        for (int i = 0; i < N - 1; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            G[a].push_back(node(b + 1, c));
            l = min(l, a); r = max(r, b + 1);
        }
        for (int i = 0; i <= r; i++) {
            G[i].push_back(node(i + 1, 0));
            G[i + 1].push_back(node(i, -1));
        }
        memset(dis, -inf, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[l] = 0;
        queue<int> q;
        while (!q.empty()) q.pop();
        q.push(l);
        vis[l] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].v;
                int w = G[u][i].w;
                if (dis[v] < dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            vis[u] = 0;//SPFA都写不对orz
        }
        cout << dis[r] << endl;
    }
    return 0;
}