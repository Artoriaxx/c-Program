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

const int N = 2e6 + 50;
int main() {
    int t; in >> t;
    while (t--) {
        ll a, b, k; in >> a >> b >> k;
        if (a > b) swap(a, b);
        double x = ((1-k)+sqrt((k-1)*(k-1) + 4*(k+1)))/2.0;
        ll l = 1, r = a;
        ll ans = -1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll now = floor(x * mid);
            if (now == a) {
                ans = mid;
                break;
            }
            else if (now < a) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ans == -1) puts("1");
        else {
            if (b != a + (k + 1) * ans) puts("1");
            else puts("0");
        }
    }
    return 0;
}
