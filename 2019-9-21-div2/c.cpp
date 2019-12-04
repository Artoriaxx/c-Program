#include <bits/stdc++.h>
using namespace std;
vector<int> G[10];
int vis[10][10];
int n, m;
int a[10];
int mp[10][10];
int ans = 0;
void dfs(int cnt) {
    if (cnt > n) {
        memset(vis, 0, sizeof(vis));
        int x = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (mp[i][j]) {
                    if (vis[a[i]][a[j]] == 1 || vis[a[j]][a[i]] == 1) {
                        continue;
                    }
                    else {
                        vis[a[i]][a[j]] = 1;
                        vis[a[j]][a[i]] = 1;
                        x++;
                    }
                }
            }
        }
        ans = max(ans, x);
        return;
    }
    for (int i = 1; i <= 6; i++) {
        a[cnt] = i;
        dfs(cnt + 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}