#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 998244353;
const int N = 2e5 + 50;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll fac[N];
ll inv[N];
ll C(int n, int m) {
    if (m == 0 || n == 0) return 1;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= m; i++) {
        fac[i] = fac[i - 1] * i % p;
        inv[i] = qpow(fac[i], p - 2);
    }

    ll ans = 0;
    for (int i = 2; i < n; i++) {
        ll maxx = max(i, n - i + 1);
        ans = (ans + C(m, n - 1) * (n - 2) % p * C(n - 3, i - 2) % p) % p;
    }
    printf("%lld\n", ans % p);
    return 0;
}