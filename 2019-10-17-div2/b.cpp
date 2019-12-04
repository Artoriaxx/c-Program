#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
const ll p = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}
int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll x = qpow(2, m) - 1;
    printf("%lld\n", qpow(x, n));
    return 0;
}