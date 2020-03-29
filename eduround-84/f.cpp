#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
const ll mod = 998244353;
ll ans[N];
ll suf1[N];
ll suf2[N];
int main() {
    int n;
    scanf("%d", &n);
    ans[n] = 10;
    ll base = 10;
    
    ll cnt = 1;
    suf1[n] = 10;
    suf2[n] = 10;
    for (int i = n - 1; i >= 1; i--) {
        base = base * 10 % mod;
        cnt++;
        ll xbase = base * cnt % mod;
        ans[i] = (xbase - suf1[i + 1] - suf2[i + 1] + mod + mod) % mod;
        suf1[i] = (suf1[i + 1] + ans[i] + mod) % mod;
        suf2[i] = (suf2[i + 1] + suf1[i] + mod) % mod;
    } 
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i] % mod)
    return 0;
}