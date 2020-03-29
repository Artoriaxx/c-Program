#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
typedef long long ll;
typedef unsigned long long ull;
ll c[N];
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
mt19937_64 rdn(time(0));
ull h[N];
ull rd[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            rd[i] = rdn();
            h[i] = 0;
            scanf("%lld", &c[i]);
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            h[v] ^= rd[u];
        }
        unordered_map<ull, ll> mp;
        for (int i = 1; i <= n; i++) {
            if (!h[i]) continue;
            mp[h[i]] += c[i];
        }
        ll ans = 0;
        for (auto e : mp) ans = gcd(ans, e.second);
        printf("%lld\n", ans);
    }
    return 0;
}