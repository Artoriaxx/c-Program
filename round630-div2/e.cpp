/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-03-31 19:44:05
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-01 15:00:00
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 50;
const ll mod = 998244353;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    if (n * m % 2 == 1) {
        printf("%lld\n", qpow((r - l + 1), n * m));
    }
    else {
        ll ans;
        if ((r - l + 1) % 2 == 0) ans = qpow(r - l + 1, n * m) * ((mod + 1) / 2) % mod;
        else ans = (qpow(r - l + 1, n * m) + 1) * ((mod + 1) / 2) % mod; 
        printf("%lld\n", ans);
    }
    return 0;
}