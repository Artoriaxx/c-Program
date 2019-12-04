#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
vector<int> G[N];
int vis[N];
int cnt;
void dfs(int u) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (vis[v]) continue;
        cnt++; vis[v] = 1; dfs(v);
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt = 0;
            vis[i] = 1;
            dfs(i);
            num += cnt;
        }
    }
    printf("%d\n", m - num);
    return 0;
}