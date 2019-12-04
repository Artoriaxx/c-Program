#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll c, sum;
        scanf("%lld%lld", &c, &sum);
        ll x = sum / c;
        ll res = sum - x * c;
        ll ans = (x + 1) * (x + 1) * res + x * x * (c - res);
        printf("%lld\n", ans);
    }
    return 0;
}