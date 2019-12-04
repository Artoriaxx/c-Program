#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
ll d[N], h[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; ll x;
        scanf("%d%lld", &n, &x);
        ll maxd = 0;
        ll maxk = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &d[i], &h[i]);
            maxk = max(maxk, d[i] - h[i]);
            maxd = max(maxd, d[i]);
        }
        if (maxk <= 0 && x > maxd) {
            puts("-1");
        }
        else {
            ll num = ceil(double(x - maxd) / maxk);
            printf("%lld\n", max(1ll, num + 1));
        }
    }
    return 0;
}