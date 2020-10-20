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
int a[N], b[N], c[N];
int ans[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 1; i <= n; i++) in >> b[i];
        for (int i = 1; i <= n; i++) in >> c[i];
        ans[1] = a[1];
        for (int i = 2; i < n; i++) {
            if (a[i] != ans[i-1]) ans[i] = a[i];
            else if (b[i] != ans[i-1]) ans[i] = b[i];
            else ans[i] = c[i];
        }
        if (a[n] != ans[n - 1] && a[n] != ans[1]) ans[n] = a[n];
        else if (b[n] != ans[n - 1] && b[n] != ans[1]) ans[n] = b[n];
        else if (c[n] != ans[n - 1] && c[n] != ans[1]) ans[n] = c[n];
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}
