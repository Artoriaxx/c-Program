#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[j][i]);
            }
        }
        for (int i = 1; i <= m; i++) sort(a[i] + 1, a[i] + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int maxx = 0, pos = 0;
            for (int j = 1; j <= m; j++) {
                if (a[j][n] > maxx) {
                    maxx = a[j][n];
                    pos = j;
                }
            }
            ans += maxx;
            for (int j = n; j >= i + 1; j--) {
                a[pos][j] = a[pos][j - 1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}