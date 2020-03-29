#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int p[N], c[N];
vector<int> a[N];
int vis[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) vis[i] = 0, a[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                a[++cnt].push_back(i);
                int now = i;
                while (1) {
                    now = p[now];
                    vis[now] = 1;
                    if (now != i) a[cnt].push_back(now);
                    else break;
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= a[i].size(); j++) {
                if (a[i].size() % j == 0) {
                    
                    for (int x = 0; x < j; x++) {
                        int cc = c[a[i][x]];
                        bool flag = true;
                        for (int k = x; k < a[i].size(); k += j) {
                            if (c[a[i][k]] != cc) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) ans = min(ans, j);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}