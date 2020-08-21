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
ll num, a, b, c;
bool check(ll x) {
    if (x >= num) return 1;
    if (x * b < c) return 0;
    ll tmp = num;
    ll now = 0;
    ll y = tmp / x;
    ll z = tmp % x;
    now = y * a;
    if (now >= b) return 1;
    else {
        ll w = z * (b - now);
        return now * x + w >= c;
    }
    
}
int main() {
    in >> a >> b >> c;
    if (a >= b) {
        printf("%lld %lld\n", (c - 1) / b + 1, (c - 1) / b + 1);
    }
    else {
        ll l = 0, r = 2e9;
        num = (c - 1) / a + 1;
        ll ans = 2e9;
        //check(10);
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%lld %lld", num, ans);
    }
    return 0;
}
