#include <bits/stdc++.h>
#define N 105
using namespace std;
const int inf = 0x3f3f3f3f;
int dis[N][N];
int power[N];
int f[1000005];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 0; i <= n; i++) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int st, ed, dist;
            scanf("%d%d%d", &st, &ed, &dist);
            dis[st][ed] = min(dis[st][ed], dist);//坑点
            dis[ed][st] = min(dis[ed][st], dist);
        }
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &power[i]);
            tot += power[i];
        }
        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int totdis = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[0][i] < inf)
                totdis += dis[0][i];
        }
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int j = totdis; j >= dis[0][i]; j--) {
                f[j] = max(f[j], f[j - dis[0][i]] + power[i]);
            }
        }
        int ans = inf;
        for (int i = 0; i <= totdis; i++) {
            if (f[i] > tot / 2) {
                ans = i;
                break;
            }
        }
        if (ans == inf) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}