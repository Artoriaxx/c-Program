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

const int N = 1e6 + 50;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1e9 + 3;
ll a[N];
ll qpow(ll aa, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * aa % p;
        aa = aa * aa % p;
        b >>= 1;
    }
    return ans;
}
int main() {
    int t; in >> t;
    while (t--) {
        ll n, p; in >> n >> p;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
        }
        if (p == 1) {
            printf("%lld\n", (n & 1));
            continue;
        }
        sort(a + 1, a + n + 1);
        ll ans1 = 0, ans2 = 0, ans3 = 0;
        for (int i = n; i >= 1; i--) {
            if (ans1 == 0 && ans2 == 0 && ans3 == 0) {
                ans1 = (ans1 + qpow(p, a[i], mod1)) % mod1;
                ans2 = (ans2 + qpow(p, a[i], mod2)) % mod2;
                ans3 = (ans3 + qpow(p, a[i], mod3)) % mod3;
            }
            else {
                ans1 = (ans1 - qpow(p, a[i], mod1) + mod1 + mod1) % mod1;
                ans2 = (ans2 - qpow(p, a[i], mod2) + mod2 + mod2) % mod2;
                ans3 = (ans3 - qpow(p, a[i], mod3) + mod3 + mod3) % mod3;
            }
        }
        printf("%lld\n", ans1);
    }
    return 0;
}
