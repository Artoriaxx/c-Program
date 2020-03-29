#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, g, b;
        scanf("%lld%lld%lld", &n, &g, &b);
        ll l = n, r = 1e18;
        ll ans = 1e18;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll x = mid / (g + b);
            ll y = min(g, mid % (g + b));
            if (x * g + y >= (n + 1) / 2) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}