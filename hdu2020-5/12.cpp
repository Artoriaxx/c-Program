#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 5e6 + 50;
const ll p = 998244353;
ll qpow(ll a, ll b) {
    ll ans = 1;
    a %= p;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll fac[N], inv[N];
ll C(ll n, ll m) {
    if (n == 0 || m == 0) return 1;
    if (m > n) return 0;
    return fac[n] * inv[n - m] % p * inv[m] % p;
}
int main() {
    fac[0] = 1; 
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = qpow(fac[i], p - 2);
    }
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        if (n == 1) {
            printf("1\n");
            continue;
        }
        for (int i = 1; i <= n / 2; i++) printf("0 ");
        ll ans1 = 0;
        for (int i = n / 2 + 1; i <= n; i++) {
            ll now = (C(i - 1, n / 2) - C(i - 1, n / 2 + 1) + p) % p;
            ans1 = (ans1 + now) % p;
        }
        //printf("%lld\n", ans1);
        //ll ans1 = (C(n - 1, n / 2) - C(n - 1, n / 2 + 1) + p) % p * (n / 2 + 1) % p;
        for (int i = n / 2 + 1; i <= n; i++) {
            ll ans2 = (C(i - 1, n / 2) - C(i - 1, n / 2 + 1) + p) % p;
            //printf("%lld ", ans2);
            if (i != n) printf("%lld ", ans2 * qpow(ans1, p - 2) % p);
            else printf("%lld\n", ans2 * qpow(ans1, p - 2) % p);
        }
    }
    return 0;
}
