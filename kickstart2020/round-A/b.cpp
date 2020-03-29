#include <bits/stdc++.h>
using namespace std;
const int N = 55;
typedef long long ll;
int a[N][N];
int pre[N][N];
int f[N * N];
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        int n, k, p;
        scanf("%d%d%d", &n, &k, &p);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                scanf("%d", &a[i][j]);
                pre[i][j] = pre[i][j - 1] + a[i][j];
            }
        }
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int v = p; v >= 0; v--) {
                for (int j = 1; j <= k; j++) {
                    if (v < j) continue;
                    f[v] = max(f[v], f[v - j] + pre[i][j]);
                }
            }
        }
        printf("Case #%d: %d\n", ++cse, f[p]);
    }
    return 0;
}