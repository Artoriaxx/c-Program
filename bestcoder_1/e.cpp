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
ll a[N];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
const ll p = 1e9 + 7;
const ll inv = (p + 1) / 2;
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
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        if (n == 1) {
            printf("%lld\n", a[1] / 2);
        }
        else {
            ll ans = 1;
            for (int i = 1; i < n; i++) {
                ll x = a[i + 1] % p * qpow(a[i], p - 2) % p;
                if (a[i + 1] % a[i] == 0)
                    ans = ans * (x + 1) % p * inv % p * a[i] % p * inv % p;
                else 
                    ans = ans * x % p * a[i] % p * inv % p;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
