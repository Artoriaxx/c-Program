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
ll a, b, c, d;
ll calc(ll z) {
    
    if (a + c >= z) {
        ll tot = (b - a + 1) * (c - b + 1);
        ll y = z - a;
        y = y - b + 1;
        ll tot2 = (y + 1) * y / 2;
        if (z - 2 * b >= 1) {
            ll x = z - 2 * b;
            tot2 -= (x + 1) * x / 2;
        }
        if (y <= 0) return tot;
        else return max(0ll, tot - tot2);
    }
    else {
        ll x = z - c;
        x++;
        x = b - x + 1;
        ll tot1 = 0;
        if (b * 2 - z > 1) {
            ll y = b * 2 - z - 1;
            tot1 = (y + 1) * y / 2;
        }
        if (x <= 0) return 0;
        else return max(0ll, (x + 1) * x / 2 - tot1);
    }
    
}
int main() {
    
    in >> a >> b >> c >> d;
    ll ans = 0;
    for (ll i = c; i <= d; i++) {
        ans += calc(i);
    }
    printf("%lld\n", ans);
    return 0;
}
