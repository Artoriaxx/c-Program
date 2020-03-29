#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
ll a[N];
const ll mod = 1e9 + 7;
ll pre[N];
ll fac[N];
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    fac[0] = 1;
    for (int i = 1; i <= n - 1; i++) fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= n - 1; i++) {
        pre[i] = (pre[i - 1] + fac[n - 1] * qpow(i, mod - 2) % mod) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans = (ans + pre[i] * (a[i + 1] - a[i] + mod) % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}