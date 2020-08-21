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

const int N = 10050;
int f[N], g[N];
int a[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, s;
        in >> n >> s;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 0; i <= s; i++) f[i] = 1e9, g[i] = -1;
        f[0] = 0, g[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = a[i]; j <= s; j++) {
                f[j] = min(f[j], f[j - a[i]] + 1);
                if (g[j - a[i]] != -1) g[j] = max(g[j], g[j - a[i]] + 1);
            }
        }
        printf("%d %d\n", f[s], g[s]);
    }
    return 0;
}
