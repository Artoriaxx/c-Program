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
ll f[N];
int main() {
    int t; in >> t;
    f[0] = 1;
    for (int i = 1; i <= 31; i++) f[i] = f[i - 1] << 1;
    while (t--) {
        int n; in >> n;
        ll l = 0, r = 0;
        for (int i = 1; i <= n / 2 - 1; i++) l += f[i];
        l += f[n];
        for (int i = n / 2; i <= n - 1; i++) r += f[i];
        printf("%lld\n", l - r);
    }
    return 0;
}
