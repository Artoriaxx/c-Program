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

const int N = 55;
int a[N][N];
int n, m; 
int main() {
    int t; in >> t;
    while (t--) {
        in >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) in >> a[i][j];
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) flag = false;
            }
            if (flag) cnt1++;
        }
        for (int i = 1; i <= m; i++) {
            bool flag = true;
            for (int j = 1; j <= n; j++) {
                if (a[j][i]) flag = false;
            }
            if (flag) cnt2++;
        }
        int x = min(cnt1, cnt2);
        if (x & 1) puts("Ashish");
        else puts("Vivek");
    }
    return 0;
}
