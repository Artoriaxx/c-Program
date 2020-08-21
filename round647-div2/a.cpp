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
        ll a, b;
        in >> a >> b;
        if (a == b) {
            puts("0");
        }
        else if (a > b) {
            int cnt = 0;
            while (a > b) {
                if (a & 1) break;
                a >>= 1;
                cnt++;
            }
            if (a == b) {
                int ans = cnt / 3;
                cnt %= 3;
                ans += cnt / 2;
                cnt %= 2;
                ans += cnt;
                printf("%d\n", ans);
            }
            else puts("-1");
        }
        else {
            int cnt = 0;
            while (a < b) {
                a <<= 1;
                cnt++;
            }
            if (a == b) {
                int ans = cnt / 3;
                cnt %= 3;
                ans += cnt / 2;
                cnt %= 2;
                ans += cnt;
                printf("%d\n", ans);
            }
            else puts("-1");
        }
    }
    return 0;
}
