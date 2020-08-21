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
        int n, m;
        in >> n >> m;
        if (m % 2 == 1 && n % 2 == 1) {
            printf("%d\n", (m - 1) * (n - 2) / 2 + n / 2 + m);
        }
        else if (m % 2 == 0 && n % 2 == 1) {
            printf("%d\n", (n - 1) / 2 * m + m / 2);
        }
        else if (m % 2 == 1 && n % 2 == 0) {
            printf("%d\n", (m - 1) / 2 * n + n / 2);
        }
        else {
            printf("%d\n", n * m / 2);
        }
    }
    return 0;
}
