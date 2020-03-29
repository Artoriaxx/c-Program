#include <bits/stdc++.h>
using namespace std;
const int N = 3550;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        if (k >= m - 1) {
            int ans = 0;
            for (int i = 1; i <= m; i++) {
                ans = max(ans, a[i]);
            }
            for (int i = n; i >= n - m + 1; i--) {
                ans = max(ans, a[i]);
            }
            printf("%d\n", ans);
        }
        else {
            int ans = 0;
            for (int i = 0; i <= k; i++) {
                int now = 2e9;
                for (int j = 0; j <= m - k - 1; j++) {
                    now = min(now, max(a[1 + i + j], a[n - (k - i) - (m - k - 1 - j)]));
                }
                ans = max(ans, now);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
