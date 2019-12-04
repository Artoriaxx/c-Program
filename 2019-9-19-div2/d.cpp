#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 50;
ll a[N], b[N];
ll f[N][3];
//0 + 1 不动
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &a[i], &b[i]);
        }
        //memset(f, 0, sizeof(f));
        f[1][1] = b[1];
        f[1][2] = 2ll * b[1];
        f[1][0] = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                f[i][0] = min(f[i - 1][1], f[i - 1][2]);
                f[i][1] = min(f[i - 1][2], f[i - 1][0]) + b[i];
                f[i][2] = min(f[i - 1][1], f[i - 1][0]) + 2ll * b[i];
            }
            else if (a[i] - a[i - 1] == 1) {
                f[i][0] = min(f[i - 1][0], f[i - 1][2]);
                f[i][1] = min(f[i - 1][0], f[i - 1][1]) + b[i];
                f[i][2] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + 2ll * b[i];
            }
            else if (a[i - 1] - a[i] == 1) {
                f[i][0] = min(f[i - 1][2], min(f[i - 1][1], f[i - 1][0]));
                f[i][1] = min(f[i - 1][2], f[i - 1][1]) + b[i];
                f[i][2] = min(f[i - 1][0], f[i - 1][2]) + 2ll * b[i];
            }
            else if (a[i] - a[i - 1] == 2) {
                f[i][0] = min(f[i - 1][1], f[i - 1][0]);
                f[i][1] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + b[i];
                f[i][2] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + 2ll * b[i];
            }
            else if (a[i - 1] - a[i] == 2) {
                f[i][0] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1]));
                f[i][1] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + b[i];
                f[i][2] = min(f[i - 1][1], f[i - 1][2]) + 2ll * b[i];
            }
            else {
                f[i][0] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1]));
                f[i][1] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + b[i];
                f[i][2] = min(f[i - 1][2], min(f[i - 1][0], f[i - 1][1])) + 2ll * b[i];
            }
        }
        printf("%lld\n", min(f[n][2], min(f[n][0], f[n][1])));
    }
    return 0;
}