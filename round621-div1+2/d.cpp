#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int dis1[N];
int disn[N];
int vis[N];
int a[N];
bool cmp(int a, int b) {
    return dis1[a] - disn[a] < dis1[b] - disn[b];
}
vector<int> G[N];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u ,v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < G[now].size(); i++) {
            int v = G[now][i];
            if (vis[v]) continue;
            else {
                dis1[v] = dis1[now] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    q.push(n);
    vis[n] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < G[now].size(); i++) {
            int v = G[now][i];
            if (vis[v]) continue;
            else {
                disn[v] = disn[now] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    sort(a + 1, a + k + 1, cmp);
    int ans = 0;
    int maxx = dis1[a[1]];
    for (int i = 2; i <= k; i++) {
        ans = max(ans, maxx + 1 + disn[a[i]]);
        maxx = max(maxx, dis1[a[i]]);
    }
    ans = min(ans, dis1[n]);
    printf("%d\n", ans);
    return 0;
}