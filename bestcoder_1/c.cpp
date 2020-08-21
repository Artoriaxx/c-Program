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

const int N = 1050;
int cnt[N][N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int f[N][N];
int main() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (gcd(i, j) == 1) {
                cnt[i][j]++;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + cnt[i][j];
        }
    }
    int t; in >> t;
    while (t--) {
        int a, b; in >> a >> b;
        printf("%d\n", f[a][b]);
    }
    return 0;
}
