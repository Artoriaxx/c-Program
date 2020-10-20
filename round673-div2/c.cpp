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

const int N = 3e5 + 50;
int a[N];
vector<int> t[N];
int ans[N];
int main() {
    int _; in >> _;
    while (_--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i], t[i].clear(), t[i].push_back(0);
        
        for (int i = 1; i <= n; i++) {
            t[a[i]].push_back(i);
            ans[i] = 1e9;
        }
        for (int i = 1; i <= n; i++) {
            t[i].push_back(n + 1);
            int len = 0;
            for (int j = 1; j < t[i].size(); j++) {
                len = max(len, t[i][j] - t[i][j - 1]);
            }
            ans[len] = min(ans[len], i);
        }
        for (int i = 2; i <= n; i++) {
            ans[i] = min(ans[i], ans[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 1e9) ans[i] = -1;
            printf("%d ", ans[i]);
        }
        puts("");
    }
    return 0;
}
