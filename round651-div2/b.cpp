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
int b[N], c[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n * 2; i++) in >> a[i]; 
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n * 2; i++) {
            if (a[i] & 1) b[++cnt1] = i;
            else c[++cnt2] = i;
        }
        if (cnt1 % 2 == 1 && cnt2 % 2 == 1) {
            cnt1--; cnt2--;
        }
        else if (cnt1 >= 2) cnt1 -= 2;
        else if (cnt2 >= 2) cnt2 -= 2;
        for (int i = 1; i <= cnt1; i+=2) {
            printf("%d %d\n", b[i], b[i+1]);
        }
        for (int i = 1; i <= cnt2; i+=2) {
            printf("%d %d\n", c[i], c[i+1]);
        }
    }
    return 0;
}
