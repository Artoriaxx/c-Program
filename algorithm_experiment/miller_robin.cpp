#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int S = 8;
long long mult_mod(ll a, ll b, ll p) {
    a %= p; b %= p;
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans += a;
            if (ans > p) ans -= p;
        }
        a <<= 1;
        if (a > p) a -= p;
        b >>= 1;
    }
    return ans;
}

ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mult_mod(ans, a, p);
        a = mult_mod(a, a, p);
        b >>= 1;
    }
    return ans;
}
//n - 1 = x * 2^t
//中间使用二次探测定理，最后使用费马小定理
//二次探测定理：如果n为素数，那么x^2同余1(mod n)的解为1或n-1
bool check(ll a, ll n, ll x, ll t) {
    ll ans = qpow(a, x, n);
    ll last = ans;
    for (int i = 1; i <= t; i++) {
        ans = mult_mod(ans, ans, n);
        if (ans == 1 && last != 1 && last != n - 1) return true;
        last = ans;
    }
    if (ans != 1) return true;
    else return false;
}

bool Miller_Rabin(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    ll x = n - 1;
    ll t = 0;
    while (!(x & 1)) {x >>= 1; t++;}
    srand(time(NULL));

    for (int i = 0; i < S; i++) {
        ll a = rand() % (n - 1) + 1;
        if (check(a, n, x, t)) return false;
    }
    return true;
}
const int N = 2e5 + 50;
int main() {
    ll n;
    while (~scanf("%lld", &n)) {
        printf("%d\n", Miller_Rabin(n));
    }
    return 0;
}
