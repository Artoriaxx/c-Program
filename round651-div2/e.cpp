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

const int N = 1e6 + 50;
char s[N], t[N];
int main() {
    int n; in >> n;
    in >> s + 1 >> t + 1;
    set<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1' && t[i] == '0') a.insert(i);
        if (s[i] == '0' && t[i] == '1') b.insert(i);
    }
    if (a.size() != b.size()) puts("-1");
    else {
        int ans = 0;
        while (!a.empty()) {
            auto it = a.begin();
            auto it2 = b.begin();
            ans++;
            while (it != a.end() && it2 != b.end()) {
                int x = *it, y = *it2;
                a.erase(it); b.erase(it2);
                if (x < y) {
                    it = a.lower_bound(y);
                    it2 = b.lower_bound(*it);
                }
                else {
                    it2 = b.lower_bound(x);
                    it = a.lower_bound(*it2);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
