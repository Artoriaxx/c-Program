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
int main() {
    ll n, d;
    in >> n >> d;
    if (d > n) {
        puts("2 0");
        return 0;
    }
    if (n == 0 && d == 0) {
        puts("2 1");
        return 0;
    }
    if (n == d) {
        printf("%lld %lld\n", n + 1, 1);
        return 0;
    }
    vector<ll> dec;
    ll x = n - d;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i > d && i != 1) dec.push_back(i);
            if (i * i != x && x / i != 1) if (x / i > d) dec.push_back(x / i);
        }
    }
    ll ans1 = 2, ans2 = 0;
    for (int i = 0; i < dec.size(); i++) {
        ll tmp = n, cnt = 0;
        while (tmp) {
            if (tmp % dec[i] == d) {
                tmp /= dec[i];
                cnt++;
            }
            else break;
        }
        if (cnt > ans2) {
            ans2 = cnt;
            ans1 = dec[i];
        }
        else if (cnt == ans2) {
            ans1 = min(ans1, dec[i]);
        }
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
