#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef _WIN32
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
        for(ch = read(),flag = 0; !isdigit(ch); ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 1e6 + 50;
const int mod = 1e9 + 7;
char s[N];
int ans[N];
int main() {
    int t; in >> t;
    while (t--) {
        in >> s + 1;
        int n = strlen(s + 1);
        ans[1] = 1;
        for (int i = 1; i <= n;) {
            int j = i, k = i + 1;
            ans[k] = k;
            while (k <= n && s[j] <= s[k]) {
                if (s[j] < s[k]) ans[k] = i, j = i;
                else ans[k] = ans[j] + k - j, j++;
                k++;
            }
            while (i <= j) i += k - j;
            ans[k] = i;
        }
        int res = 0, base = 1;
        for (int i = 1; i <= n; i++) {
            res = (res + 1ll * ans[i] * base % mod) % mod;
            base = 1ll * base * 1112 % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}


