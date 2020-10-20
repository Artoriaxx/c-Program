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
ll f[N];
int main() {
    int t; in >> t;
    f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = f[i - 1] * 2 + 1;
        if (f[i] > 1e18) break;
    }
    for (int i = 1; i < N; i++) {
        f[i] = (1 + f[i]) * f[i] / 2;
        if (f[i] > 1e18 || f[i] < 0) break;
    }
    while (t--) {
        ll x; in >> x;
        ll tot = 0;
        int ans = 0;
        for (int i = 1; i < N; i++) {
            tot += f[i];
            if (tot <= x) ans = i;
            else break; 
        }
        printf("%d\n", ans);
    }
    return 0;
}
