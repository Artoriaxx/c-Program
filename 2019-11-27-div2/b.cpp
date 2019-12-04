#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll r, b, k;
        scanf("%lld%lld%lld", &r, &b, &k);
        if (r > b) swap(r, b);
        if (b % r == 0) {
            if (b / r - 1 < k)
                puts("OBEY");
            else puts("REBEL");
            continue;
        }
        ll y = gcd(r, b);
        ll x = (b - y) / r;
        if ((b - y) % r == 0) x--;
        x++;
        if (x < k) puts("OBEY");
        else puts("REBEL");
    }
    return 0;
}