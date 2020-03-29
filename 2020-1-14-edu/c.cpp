#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll f[11][1005];
ll g[11][1005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    f[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) g[1][i] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                g[i][j] = (g[i][j] + g[i - 1][k]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = (ans + f[m][i] * g[m][j] % mod) % mod;
        }
    }
    printf("%lld\n", ans);
    // for (int i = 1; i <= n; i++) {
    //     printf("%lld ", g[m][i]);
    // }
    return 0;
}