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
ll fst(ll x,ll y){ll ret;for(ret=1;y;y/=2,x=1ll*x*x)if(y&1)ret=1ll*ret*x;return ret;}
ll gcd(ll x,ll y){return !y ? x : gcd(y,x%y);}

int main() {
    ll a, b, c, d, x, y;
    in >> a >> b >> c >> d >> x >> y;
    ll ans = 1;
    for (int i = a; i <= b; i++) {
        for (int j = c; j <= d; j++) {
            ans = ans * gcd(fst(x, i), fst(y, j)) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
