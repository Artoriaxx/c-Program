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

const int N = 50;
int a[N][N];
int f[N*N];
int num[N*N][2];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                in >> a[i][j];
        for (int i = 1; i <= n * m; i++) {
            f[i] = i;
            num[i][0] = num[i][1] = 0;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = n + m + 2 - (i + j);
                for (int ii = 1; ii <= n; ii++) {
                    int jj = x - ii;
                    if (jj >= 1 && jj <= m && ii >= i && jj >= j) {
                        int l = find((i - 1) * m + j);
                        int r = find((ii - 1) * m + jj);
                        if (l != r) f[r] = l;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                num[find((i-1)*m+j)][a[i][j]]++;
            }
        }
        for (int i = 1; i <= n * m; i++) {
            ans += min(num[i][0], num[i][1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
