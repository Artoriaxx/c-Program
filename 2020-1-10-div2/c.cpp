#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 1e15;
ll ansa, ansb;
vector<ll> v;
void dfs(ll a, ll b, int cnt) {
    if (cnt >= v.size()) {
        if (max(a, b) < ans) {
            ans = max(a, b);
            ansa = a, ansb = b;
        }
        return;
    }
    if (max(a, b) >= ans) return;
    dfs(a * v[cnt], b, cnt + 1);
    if (max(a, b) >= ans) return;
    dfs(a, b * v[cnt], cnt + 1);
}
int main() {
    ll x;
    scanf("%lld", &x);
    
    for (ll i = 2; i * i <= x; i++) {
        ll tmp = 1;
        while (x % i == 0) {
            tmp *= i;
            x /= i;
        }
        if (tmp != 1) v.push_back(tmp);//写错n次
    }
    if (x > 1) v.push_back(x);
    sort(v.begin(), v.end());
    dfs(1, 1, 0);
    printf("%lld %lld\n", ansa, ansb);
    return 0;
}