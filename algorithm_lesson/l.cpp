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

const int N = 1e5 + 50;
int f[15][N];
int update(int a, int b) {

} 
int main() {
    int t; in >> t;
    while (t--) {
        int n, k, p; in >> n >> k >> p;
        int mx = 0;
        f[0][0] = 1;
        for (register int i = 1; i <= k; i++) mx += n - i + 1;
        for (register int i = 1; i <= k; i++) {
            for (register int j = i; j <= mx; j++) {
                f[i][j] = (f[i - 1][j - i] + f[i][j - i]) % p;
                if (j > n) f[i][j] = (f[i][j] - f[i - 1][j - n - 1] + p) % p;
            }
        }
        int ans = 0;
        for (register int i = 0; i <= k; i++) {
            for (register int j = 0; j <= mx; j++) {
                ans = (ans + f[i][j] * f[k - i][j] % p) % p;
                if (i < k) ans = (ans + f[i][j] * f[k - i - 1][j] % p) % p;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
