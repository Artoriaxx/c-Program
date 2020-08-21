#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 1e5 + 50;
const int inf = 0x3f3f3f3f;
char a[N];
char b[25];
int f[N][30];
int g[30][30];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s%s", a + 1, b + 1);
        int n = strlen(a + 1);
        int m = strlen(b + 1);
        memset(f, inf, sizeof(f));
        for (int i = n; i >= 1; i--) {
            f[i][a[i] - 'a' + 1] = i;
            for (int j = 1; j <= 26; j++) {
                f[i][j] = min(f[i][j], f[i + 1][j]);
            }
        }
        int q; scanf("%d", &q);
        while (q--) {
            memset(g, inf, sizeof(g));
            int l, r; scanf("%d%d", &l, &r);
            for (int i = 0; i <= m; i++) g[i][0] = l - 1;
            int ans = m + r - l + 1;
            for (int i = 1; i <= m; i++) {
                int x = b[i] - 'a' + 1;
                for (int j = 1; j <= i; j++) {
                    g[i][j] = g[i - 1][j];
                    int pos = g[i - 1][j - 1];
                    if (pos < inf) g[i][j] = min(g[i][j], f[pos + 1][x]);
                    if (g[i][j] <= r) ans = min(ans, m + r - l + 1 - 2 * j);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
