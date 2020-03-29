#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50];
ll p[100];
int vis[100];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        ll maxx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            maxx = max(maxx, a[i]);
        }
        memset(vis, 0, sizeof(vis));
        p[0] = 1;
        int pos = 0;
        for (int i = 1; i <= 100; i++) {
            p[i] = p[i - 1] * (ll)k;
            if (p[i] > maxx) {
                pos = i;
                break;
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int tmp = pos;
            while (a[i]) {
                bool f1 = false;
                for (int j = tmp; j >= 0; j--) {
                    if (a[i] >= p[j]) {
                        if (!vis[j]) {
                            a[i] -= p[j];
                            vis[j] = 1;
                            tmp = j - 1;
                            f1 = true;
                            break;
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
                if (!f1) flag = false;
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}