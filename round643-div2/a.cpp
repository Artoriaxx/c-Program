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
    int t; in >> t;
    while (t--) {
        ll a1, k;
        in >> a1 >> k;
        k--;
        ll mn = 10, mx = 0;
        ll now = a1;
        while (mn != 0 && k--) {
            ll tmp = now;
            mn = 10, mx = 0;
            while (tmp) {
                mn = min(mn, tmp % 10);
                mx = max(mx, tmp % 10);
                tmp /= 10;
            }
            if (!mn) break;
            else now += mn * mx;
        }
        printf("%lld\n", now);
    }
    return 0;
}
