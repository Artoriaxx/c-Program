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
    int t; in >> t;
    while (t--) {
        ll m, p, q;
        in >> m >> p >> q;
        ll ans = (m - (m * 100 % mod * qpow(p, mod - 2) % mod - 1 + mod) % mod * q % mod * qpow(100, mod - 2) % mod) % mod;
        while (ans < 0) ans += mod;
        while (ans >= mod) ans -= mod;
        //ll ans1 = (100 * p * m - 100 * q * m - p * q + mod * 100000) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
