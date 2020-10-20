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
vector<ll> S;
void get_S(int x) {
    S.clear();
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        int tmp = 1;
        while (x % i == 0) {
            tmp *= i;
            x /= i;
        }
        S.push_back(tmp);
    }
    if (x != 1) S.push_back(x);
}
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else {
        exgcd(b, a % b, x, y);
        ll tmp = y;
        y = x - a / b * y;
        x = tmp;
    }
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int t;
    in >> t;
    while (t--) {
        ll a, b;
        in >> a >> b;
        if (b == 1) {
            puts("-1 -1 -1 -1");
            continue;
        }
        ll x = gcd(a, b);
        if (x == 1) {
            get_S(b);
            if (S.size() == 1) {
                puts("-1 -1 -1 -1");
                continue;
            }
            else {
                ll c, d, e, f;
                d = S[0];
                f = b / d;
                exgcd(f, d, c, e);
                if (c < 0) {
                    swap(c, e);
                    swap(d, f);
                }
                ll x = c / d;
                c -= x * d;
                e += x * f;
                if (c * a > 1e12 || -e * a > 1e12) puts("-1 -1 -1 -1");
                else {
                    printf("%lld %lld %lld %lld\n", 1ll * c * a, d, -1ll * e * a, f);
                }
            }
        }
        else {
            b /= x;
            a /= x;
            printf("%lld %lld %lld %lld\n", a + 1, b, 1ll, b);
        }
    }
    return 0;
}
