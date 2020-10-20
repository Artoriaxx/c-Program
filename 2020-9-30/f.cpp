#include <bits/stdc++.h>
using namespace std;
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
#define int long long
const int N = 2e5 + 50;
const int p = 1e9 + 7;
int a[N], b[N];
int vis[N];
int f[N];
signed main() {
    int n, m;
    int cse = 0;
    while (~scanf("%lld%lld", &n, &m)) {
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
        int tmp = max(n, m);
        for (int i = 0; i <= tmp; i++) vis[i] = 0, f[i] = 0;
        for (int i = 0; i < m; i++) {
            if (vis[i]) continue;
            int len = 1;
            int now = i;
            vis[now] = 1;
            while (b[now] != i) {
                now = b[now];
                vis[now] = 1;
                len++;
            }
            f[len]++;
        }
        for (int i = 0; i <= n; i++) vis[i] = 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int len = 1;
            int now = i;
            vis[now] = 1;
            while (a[now] != i) {
                now = a[now];
                vis[now] = 1;
                len++;
            }
            int sum = 0;
            for (int j = 1; j * j <= len; j++) {
                if (len % j == 0) {
                    sum = (sum + 1ll * f[j] * j % p) % p;
                    int x = len / j;
                    if (j * j != len) sum = (sum + 1ll * f[x] * x % p) % p;
                }
            }
            ans = 1ll * ans * sum % p;
        }

        printf("Case #%lld: %lld\n", ++cse, ans);
    }
    return 0;
}
