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
char s[N];
int nxt[N];
int len;
void getNext(char s[]) {
	nxt[1] = 0;
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}
int f[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        len = strlen(s + 1);
        sort(s + 1, s + len + 1);
        for (int i = 1; i <= len + 1; i++) f[i] = 0, nxt[i] = 0;
        getNext(s);
        
        int ans = 0;
        for (int i = 1; i <= len; i++) {
            f[i] = f[nxt[i]] + 1;
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);

    }
    return 0;
}
