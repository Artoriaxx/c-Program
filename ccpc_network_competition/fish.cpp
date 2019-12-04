#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
ll a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        ll cnt = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i];
            cnt += a[i] / k;
            a[i] %= k;
        }
        sort(a + 1, a + n + 1);
        for (int i = n; i >= 1; i--) {
            if (cnt >= n - 1) break;
            cnt++; ans += k - a[i];
        }
        printf("%lld\n", ans + k);
    }
    return 0;
}