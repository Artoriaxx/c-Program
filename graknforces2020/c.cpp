#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
int a[N];
double f[N], g[N];
const double eps = 1e-8;
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, l; in >> n >> l;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
        }
        a[0] = 0;
        a[n+1] = l;
        f[0] = g[n+1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            f[i] = f[i - 1] + 1.0 * (a[i] - a[i - 1]) / (1.0 * i);
        }
        for (int i = n; i >= 0; i--) {
            g[i] = g[i + 1] + 1.0 * (a[i + 1] - a[i]) / (1.0 * (n - i + 1));
        }
        db ans;
        for (int i = 0; i <= n + 1; i++) {
            if (sgn(f[i] - g[i]) == 0) {
                ans = f[i];
                break;
            }
            else if (sgn(f[i] - g[i]) == 1) {
                ans = (db)(a[i] - a[i - 1] + 1.0 * f[i - 1] * 1.0 * i + 1.0 * g[i] * 1.0 * (n - i + 2)) / (db)(n + 2); 
                break;
            }
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
