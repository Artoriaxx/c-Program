#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 450;
const int inf = 0x3f3f3f3f;
struct node {
    int u, v, cap, nxt;
    node () {}
    node (int u, int v, int cap, int nxt): u(v), v(v), cap(cap), nxt(nxt) {}
} edge[N * N];
int head[N], tot;
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}
int dep[N];
void adde(int u, int v, int w) {
    edge[tot] = node(u, v, w, head[u]);
    head[u] = tot++;
    edge[tot] = node(v, u, 0, head[v]);
    head[v] = tot++;
}
bool bfs(int s, int t) {
    queue<int> q;
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (edge[i].cap > 0 && dep[v] == -1) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[t] > 0;
}
int dfs(int u, int t, int f) {//f是到这点的残余流量，used是这点已经流出的流量
    if (u == t) return f;
    int w, used = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        int cap = edge[i].cap;
        if (cap && dep[v] == dep[u] + 1) {
            w = f - used;
            w = dfs(v, t, min(w, cap));
            edge[i].cap -= w;
            edge[i ^ 1].cap += w;
            used += w;
            if (used == f) return f;
        }
    }
    if (!used) dep[u] = -1;
    return used;
}
int dinic(int s, int t) {
    int maxflow = 0;
    while (bfs(s, t)) {
       maxflow += dfs(s, t, inf);
    }
    return maxflow;
}
int G[N][N];
int vis[N];
int main() {
    int n, s, t;
    while (~scanf("%d%d%d", &n, &s, &t)) {
        init();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) adde(i, i + n, 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &G[i][j]);
                if (!G[i][j]) continue;
                //if (j >= i) continue; 加了这句就wa，不知为何，网络流不应该单向边双向边无所谓的吗
                adde(i + n, j, inf);
            }
        }
        if (G[s][t] || s == t) {
            puts("NO ANSWER!");
            continue;
        }
        int mf = dinic(s + n, t);
        printf("%d\n", mf);
        if (mf == 0) continue;
        vector<int> ans;
        ans.clear();
        for (int i = 1; i <= n; i++) {
            if (i == s || i == t) continue;
            if (mf == 0) break;
            vis[i] = 1;
            init();
            for (int j = 1; j <= n; j++) {
                if (vis[j] == 0) adde(j, j + n, 1);
                else  adde(j, j + n, 0);
            }
            for (int k = 1; k <= n; k++) {
                for (int j = 1; j <= n; j++) {
                    if (!G[k][j]) continue;
                    adde(k + n, j, inf);
                }
            }
            int now = dinic(s + n, t);
            if (now < mf) {
                ans.push_back(i);
                mf--;
            }
            else {
                vis[i] = 0;
            }
            
        }
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i++) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}