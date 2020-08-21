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
int a[N];
int b[N];
int f[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= 2 * n; i++) in >> a[i];
        int cnt = 0;
        for (int i = 1; i <= 2 * n; i++) {
            int now = a[i];
            int len = 1;
            while (i + 1 <= 2 * n && now > a[i + 1]) {
                i++;
                len++;
            }
            b[++cnt] = len;
        }
        f[0] = 1;
        for (int i = 1; i <= n; i++) f[i] = 0;
        for (int i = 1; i <= cnt; i++) {
            for (int j = n; j >= b[i]; j--) {
                f[j] |= f[j - b[i]];
            }
        }
        if (f[n]) puts("YES");
        else puts("NO");
    }
    return 0;
}
