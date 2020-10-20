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
int ans[N];
bool flag = false;
int n, a, b, c; 
int vis[N];
void dfs(int dep) {
    if (flag) {
        return;
    }
    if (dep > n) {
        int mx = 0;
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] >= mx) cnta++, vis[i] = 1, mx = ans[i];
        }
        mx = 0;
        for (int i = n; i >= 1; i--) {
            if (ans[i] >= mx) {
                mx = ans[i];
                cntb++;
                if (vis[i]) cntc++;
            }
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        if (cnta == a && cntb == b && cntc == c) {
            puts("1");
            flag = true;
        }
        // if (ans[1] == 4 && ans[2] == 1 && ans[3] == 3 && ans[4] == 2) {
        //     printf("%d %d %d %d\n", ans[1], ans[2], ans[3], ans[4]);
        // }
        return;
    }
    for (int i = 1; i <= n; i++) {
        ans[dep] = i;
        dfs(dep + 1);
    }
}
int main() {
    int tc; in >> tc;
    for (int t = 1; t <= tc; t++) {
        in >> n >> a >> b >> c;
        flag = false;
        dfs(1);
        if (!flag) puts("-1");
    }    
    return 0;
}
