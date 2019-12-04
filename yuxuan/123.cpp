#include <bits/stdc++.h>
#define pii pair<int, int>
#define N 100050
using namespace std;
struct node {
    int v, val;
    node() {}
    node(int v, int val): v(v), val(val) {} 
};
vector<node> G[N];
int vis[N];
void dijkstra(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    fill(vis, vis + n + 1, false);
    fill(d + 1, d + n + 1, inf);
    d[s] = 0;
    vis[s] = true;
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        pii now = q.top(); q.pop();
        int x = now.second;
        for (int i = 0; i < G[x].size(); i++) {
            int v = G[x][i].v;
            if (vis[v]) continue;
            if (d[v] > d[x] + G[x][i].val) 
        }
    }
}
int main() {

}