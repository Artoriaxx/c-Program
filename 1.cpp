#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
struct node {
    int v, w;
    node(int v = 0, int w = 0): v(v), w(w) {}
    bool operator < (const node &b) const {
        return w > b.w;
    }
};
vector<node> G[N];

int d[N];
int vis[N];
int n;
void dijkstra(int s) {
    for (int i = 1; i <= n; i++) d[i] = 1e9 + 50, vis[i] = 0;
    priority_queue<node> q;
    d[s] = 0;
    q.push(node(s, d[s]));
    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (vis[now.v]) continue;
        vis[now.v] = 1;
        for (auto i : G[now.v]) {
            if (d[i.v] > now.w + i.w) {
                d[i.v] = now.w + i.w;
                if (!vis[i.v]) q.push(node(i.v, d[i.v]));
            }
        }
    }
}
int main() {
    int m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(node(v, w));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }
    return 0;
}