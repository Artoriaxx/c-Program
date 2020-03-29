#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 50;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = a[1];
        for (int i = 2; i <= n; i++) {
            if ((i - 1) * a[i] <= d) {
                d -= (i - 1) * a[i];
                ans += a[i];
            }
            else {
                ans += d / (i - 1);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}