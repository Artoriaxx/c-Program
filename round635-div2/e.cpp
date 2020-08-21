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

const int N = 3050;
const ll p = 998244353;
char s[N], t[N];
ll dp[N][N];
int main() {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        if (s[1] == t[i] || i > m) dp[i][i] = 2;
    }
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= n - i + 1; l++) {
            int r = i + l - 1;
            if (l > m || s[i] == t[l]) (dp[l][r] += dp[l + 1][r]) %= p;
            if (r > m || s[i] == t[r]) (dp[l][r] += dp[l][r - 1]) %= p;
        }
    }
    ll ans = 0;
    for (int i = m; i <= n; i++) {
        (ans += dp[1][i]) %= p;
    }
    printf("%lld\n", ans);
    return 0;
}
