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
string s = "codeforces";
int main() {
    ll k; in >> k;
    ll pos = 1;
    for (ll i = 1; i <= 100; i++) {
        ll ans = 1;
        for (int j = 1; j <= 10; j++) {
            ans = ans * i;
        }
        if (ans > k) break;
        pos = i;
    }
    ll now = 1;
    for (int i = 1; i <= 10; i++) now *= pos;
    int cnt = 0;
    while (now < k) {
        now = now / pos;
        now *= pos + 1;
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < pos + 1; j++) {
            putchar(s[i]);
        }
    }
    for (int i = cnt; i < 10; i++) {
        for (int j = 0; j < pos; j++) {
            putchar(s[i]);
        }
    }

    return 0;
}
