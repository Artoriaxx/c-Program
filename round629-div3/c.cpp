#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
char s[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll l = 0, r = n + 1e9;
        ll ans = 1e18;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if ((mid + 1) * mid / 2 >= k) {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        ll x1 = n - ans;
        ll a = k - (ans - 1) * ans / 2 ;
        ll x2 = n - a + 1;
        for (int i = 1; i <= n; i++) {
            if (i == x1 || i == x2) putchar('b');
            else putchar('a');
        }
        puts("");
    }
    return 0;
}