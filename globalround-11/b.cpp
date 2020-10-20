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
struct node {
    int l, r, len;
    bool operator < (const node &b) const {
        return len < b.len;
    }
};
int main() {
#ifdef Artoriax
    freopen("F://c++program//in.txt", "r", stdin);
#endif
    int t; in >> t;
    while (t--) {
        int n, k; in >> n >> k;
        in >> s + 1;
        int l = 0;
        vector<node> v;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'W') {
                if (l) v.push_back(node{l + 1, i - 1, i - l - 1});
                l = i;
            }
        }
        sort(v.begin(), v.end());
        for (auto now : v) {
            if (now.l > now.r) continue;
            for (int i = now.l; i <= now.r && k > 0; i++, k--) {
                s[i] = 'W';
            }
        }
        //printf("%s\n", s + 1);
        if (k > 0) {
            int r = n + 1;
            l = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i] == 'W') break;
                l = i;
            }
            for (int i = n; i >= 1; i--) {
                if (s[i] == 'W') break;
                r = i;
            }
            for (int i = l; i >= 1 && k > 0; i--, k--) s[i] = 'W';
            for (int i = r; i <= n && k > 0; i++, k--) s[i] = 'W';
        }
        //printf("%s\n", s + 1);
        int ans = 0, f1 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'W') {
                if (f1) ans += 2;
                else ans += 1;
                f1 = 1;
            }
            else f1 = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
