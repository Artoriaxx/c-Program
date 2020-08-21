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
ll h, c, t;
ll calc(ll x) {
    return (x + 1) * h + x * c;
}
int main() {
    int tc; in >> tc;
    while (tc--) {
        
        in >> h >> c >> t;
        ll l = 0, r = 1e12;
        ll ans1 = 1e12;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (calc(mid) <= (mid * 2 + 1) * t) {
                r = mid - 1;
                ans1 = min(ans1, mid);
            }
            else l = mid + 1;
        }
        l = 0, r = 1e12;
        ll ans2 = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (calc(mid) >= (mid * 2 + 1) * t) {
                l = mid + 1;
                ans2 = max(ans2, mid);
            }
            else r = mid - 1;
        }
        double a1 = fabs(t - 1.0 * ((ans1 + 1) * h + ans1 * c) / (2.0 * ans1 + 1));
        double a2 = fabs(t - 1.0 * ((ans2 + 1) * h + ans2 * c) / (2.0 * ans2 + 1));
        double a3 = fabs(t - 1.0 * (h + c) / 2.0);
        if (a3 <= a1 && a3 <= a2) {
            printf("2\n");
        }
        else if (a2 <= a3 && a2 <= a1) {
            printf("%lld\n", ans2 * 2 + 1);
        }
        else {
            printf("%lld\n", ans1 * 2 + 1);
        }
    }
    return 0;
}
