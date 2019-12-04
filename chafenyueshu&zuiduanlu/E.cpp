#include <bits/stdc++.h>
#define N 305
using namespace std;
const int inf = 0x3f3f3f3f;
int dis[N][N];
int dp[N][N];
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        memset(dis, 0x3f, sizeof(dis));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dis[i][i] = 0;
            dp[i][i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (v == u) continue;//注意v和u相等的时候不要把dp[u][v],dp[v][u]更新为2
            dis[u][v] = min(dis[u][v], w);
            dis[v][u] = min(dis[v][u], w);
            dp[u][v] = dp[v][u] = 2;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        dp[i][j] = dp[i][k] + dp[k][j] - 1;
                    }
                    else if (dis[i][j] == dis[i][k] + dis[k][j]) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] - 1);
                    }
                }
            }
        }
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[a][i] + dis[i][j] + dis[j][b] == dis[a][b] && dis[c][i] + dis[i][j] + dis[j][d] == dis[c][d]) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}