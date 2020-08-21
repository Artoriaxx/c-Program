#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 2050;
int a[N];
int sum[N];
int f[N][30];
int calc(int x) {
    if (x % 10 <= 4) return x / 10 * 10;
    else return x / 10 * 10 + 10;
}
int main() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    memset(f, 0x7f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        f[i][1] = calc(sum[i]);
    }
    for (int i = 2; i <= d + 1; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i - 1; k <= j - 1; k++) {
                f[j][i] = min(f[j][i], f[k][i - 1] + calc(sum[j] - sum[k]));
            }
        }
    }
    int ans = 0x7fffffff;
    for (int i = 1; i <= min(n, d + 1); i++) {
        ans = min(ans, f[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}
