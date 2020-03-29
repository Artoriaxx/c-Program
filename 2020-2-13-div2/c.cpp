#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll tot = (n + 1) * n / 2;
        ll x = (n - m) / (m + 1);
        ll y = (n - m) % (m + 1);
        printf("%lld\n", tot - (x + 1) * x / 2 * (m + 1) - (x + 1) * y); 
    }
    return 0;
}