#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int main() {
    //printf("%lld\n", qpow(2, 10));
    ll x, n;
    scanf("%lld%lld", &x, &n);
    ll ans = 1;
    for (ll i = 2; i * i <= x; i++) {
        bool flag = false;
        while (x % i == 0) {
            flag = true;
            x /= i;
        }
        if (flag) {
            ll tmp = n;
            ll cnt = 0;
            while (tmp >= i) {
                cnt += tmp / i;
                tmp /= i;
            }
            ans = ans * qpow(i, cnt) % p;
        }
        
    }
    ll tmp = n;
    ll cnt = 0;
    if (x != 1) {
        while (tmp >= x) {
            cnt += tmp / x;
            tmp /= x;
        }
        ans = ans * qpow(x, cnt) % p;
    }
    
    printf("%lld\n", ans);
    return 0;
}