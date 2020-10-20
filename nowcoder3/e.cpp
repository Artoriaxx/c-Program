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
const ll inf = 1e18;
const int N = 2e5 + 50;
int a[N];
ll dp[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        sort(a + 1, a + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i+=2) ans += a[i+1] - a[i];
        for (int i = 1; i <= n; i++) dp[i] = inf;
        dp[0] = 0;
        for (int i = 4; i <= n; i++) {
            if (dp[i - 4] != inf) {
                int ba = i - 3;
                ll cur = min(a[ba + 2] - a[ba] + a[ba + 3] - a[ba + 1], a[ba + 3] - a[ba] + a[ba + 2] - a[ba + 1]);
                dp[i] = min(dp[i], dp[i - 4] + cur);
            }
            if (i - 6 >= 0 && dp[i - 6] != inf) {
                int ba = i - 5;
                ll cur = a[ba + 2] - a[ba + 1] + a[ba + 4] - a[ba + 3] + a[ba + 5] - a[ba];
                dp[i] = min(dp[i], dp[i - 6] + cur);
            }
        }
        ans = ans + dp[n];
        printf("%lld\n", ans);
    }
    return 0;
}