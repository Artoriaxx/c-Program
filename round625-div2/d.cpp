#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 2e5 + 50;
int d[N];
int vis[N];
int can[N];
int n, m;
vector<int> G[N];
void dijkstra(int s) {
    priority_queue<pi, vector<pi>, greater<pi> > q;
    fill(d + 1, d + n + 1, 0x7fffffff);
    d[s] = 0;
    fill(vis, vis + n + 1, false);
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        pi now = q.top(); q.pop();
        int x = now.second;
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = 0; i < G[x].size(); i++) {
            int v = G[x][i];
            if (d[v] > d[x] + 1) {
                d[v] = d[x] + 1;
                q.push(make_pair(d[v], v));
            }
            else if (d[v] == d[x] + 1) {
                q.push(make_pair(d[v], v));
                can[v]++;
            }
        }
    }
}
int route[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
    }
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        scanf("%d", &route[i]);
    }
    dijkstra(route[x]);
    int ans = 0, minn = 0;
    for (int i = 1; i < x; i++) {
        if (d[route[i + 1]] - d[route[i]] != -1) {
            minn++;
            ans++;
        }
        else if (can[route[i]] > 0 && i != x - 1) {
            ans++;
        }
    }
    printf("%d %d\n", minn, ans);
    return 0;
}