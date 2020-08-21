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

const int N = 2050;
char s[N][N];
int dp[N][N][4];
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1) dp[i][j][0] = 1;
            else if (s[i - 1][j] != s[i][j] || s[i][j - 1] != s[i][j]) dp[i][j][0] = 1;
            else dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (i == 1 || j == m) dp[i][j][1] = 1;
            else if (s[i - 1][j] != s[i][j] || s[i][j + 1] != s[i][j]) dp[i][j][1] = 1;
            else dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j + 1][1]) + 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (i == n || j == 1) dp[i][j][2] = 1;
            else if (s[i + 1][j] != s[i][j] || s[i][j - 1] != s[i][j]) dp[i][j][2] = 1;
            else dp[i][j][2] = min(dp[i + 1][j][2], dp[i][j - 1][2]) + 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n || j == m) dp[i][j][3] = 1;
            else if (s[i + 1][j] != s[i][j] || s[i][j + 1] != s[i][j]) dp[i][j][3] = 1;
            else dp[i][j][3] = min(dp[i + 1][j][3], dp[i][j + 1][3]) + 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1 || i == n || j == m) ans++;
            else if (s[i + 1][j] != s[i][j] || s[i - 1][j] != s[i][j] || s[i][j - 1] != s[i][j] || s[i][j + 1] != s[i][j]) ans++;
            else {
                ans += min(dp[i][j][0], min(dp[i][j][1], min(dp[i][j][2], dp[i][j][3])));
                
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
