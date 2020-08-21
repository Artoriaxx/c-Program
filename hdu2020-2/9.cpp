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

const int N = 405;
int a[N][N];
char s[(int)4e6+5];
int edge[N][N];
int vis[N*N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, m, q;
        in >> n >> m >> q;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                in >> a[i][j];
        while (q--) {
            int x, y;
            in >> x >> y >> s;
            int len = strlen(s);
            int l = x + 1, r = x, d = y + 1, u = y;
            for (int i = 0; i < len; i++) {
                if (s[i] == 'L') {
                    edge[x][y+1] = 1;
                    x--;
                }
                if (s[i] == 'R') {
                    x++;
                    edge[x][y+1] = 1;
                }
                if (s[i] == 'U') y++;
                if (s[i] == 'D') y--;
                l = min(l, x + 1), r = max(r, x);
                d = min(d, y + 1), u = max(u, y);
            }
            
            int ans = 0;
            for (int i = l; i <= r; i++) {
                int cnt = 0;
                for (int j = d; j <= u; j++) {
                    cnt ^= edge[i][j];
                    if (cnt & 1 && !vis[a[i][j]]) {
                        vis[a[i][j]] = 1;
                        ans++;
                    }
                }
            }
            for (int i = l - 1; i <= r + 1; i++) 
                for (int j = d - 1; j <= u + 1; j++) edge[i][j] = vis[a[i][j]] = 0;
            printf("%d\n", ans);
        }
    }
    return 0;
}
