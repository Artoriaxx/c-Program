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
const ll p = 1e9 + 7;
int main() {
    ll n, k;
    in >> n >> k;
    ll ans = 0;
    for (ll l = 1, r; l <= k; l = r + 1ll) {
        ll x = (n / l);
        if (x == 0) break;
        r = n / x;
        r = min(r, k);
        ans = (ans + ((r - l + 1ll) % p) * ((n / l) % p) % p) % p;
    }
    for (ll l = 2, r; l <= k; l = r + 1ll) {
        ll x = (n - 1ll) / l;
        if (x == 0) {
            ans = (ans + k - l + 1ll) % p;
            break;
        }
        r = (n - 1ll) / x;
        r = min(r, k);
        ans = (ans + ((r - l + 1ll) % p) * (((n - 1ll) / l + 1ll) % p) % p) % p;
    }
    printf("%lld\n", ans);
    return 0;
}
//1000000000000 1000000000000