#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
vector<int> G[N];
int cor[N];
int maxx = 0;
void dfs(int u, int c) {
    cor[u] = c;
    maxx = max(u, maxx);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!cor[v]) {
            dfs(v, c);
        }
    }
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cor[i]) continue;
        if (!cor[i] && i < maxx) {
            ans++;
        }
        dfs(i, 1);
    }
    printf("%d\n", ans);
    return 0;
}