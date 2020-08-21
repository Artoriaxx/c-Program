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
const int p = 23333333;
int f[N];
int g[350][N];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[0] = 1;
        int sz = sqrt(n);
        for (int i = 1; i <= sz; i++) {
            for (int j = i; j <= n; j++) f[j] = (f[j] + f[j - i]) % p;
            for (int j = n; j >= i * (i + 1); j--) f[j] = (f[j] + p - f[j - i * (i + 1)]) % p;
        }
        g[0][0] = 1;
        int ans = f[n];
        for (int i = 1; i <= sz; i++) {
            for (int j = (sz + 1) * i; j <= n; j++) {
                g[i][j] = (g[i - 1][j - (sz + 1)] + g[i][j - i]) % p;
                ans = (ans + 1ll * f[n - j] * g[i][j] % p) % p;
            }
        }
        //printf("%lld %lld\n", g[sz][n], f[sz]);
        printf("%d\n", ans);
    }
    
    return 0;
}
