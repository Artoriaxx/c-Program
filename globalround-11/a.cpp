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
int main() {
#ifdef Artoriax
    freopen("F://c++program//in.txt", "r", stdin);
#endif
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) in >> a[i], sum += a[i];
        if (sum == 0) puts("NO");
        else {
            puts("YES");
            sort(a + 1, a + n + 1);
            if (sum > 0) {
                for (int i = n; i >= 1; i--) {
                    printf("%d ", a[i]);
                }
                puts("");
            }
            else {
                for (int i = 1; i <= n; i++) printf("%d ", a[i]);
                puts("");
            }
        }
    }
    return 0;
}
