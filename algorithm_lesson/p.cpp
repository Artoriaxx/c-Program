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

const int N = 2e5 + 50;
ll dp[50][2000];
ll f[50][50][2000];
int digit[50];
ll l, r; int k;
ll dfs(int pos, int sum, int flag) {
    if (pos == 0) return sum;
    if (!flag && dp[pos][sum] != -1) return dp[pos][sum];
    int sz = flag ? digit[pos] : k - 1;
    ll ans = 0;
    for (int i = 0; i <= sz; i++) {
        ans += dfs(pos - 1, sum + (pos - 1) * i, flag && (i == sz));
    }
    if (!flag) dp[pos][sum] = ans;
    return ans;
}
ll dfs1(int pos, int sum, int flag, int x) {
    if (sum < 0) return 0;
    if (pos == 0) return sum;
    if (!flag && f[x][pos][sum] != -1) return f[x][pos][sum];
    int sz = flag ? digit[pos] : k - 1;
    ll ans = 0;
    for (int i = 0; i <= sz; i++) {
        if (pos >= x) ans += dfs1(pos - 1, sum + i, flag && (i == sz), x);
        else ans += dfs1(pos - 1, sum - i, flag && (i == sz), x);
    }
    if (!flag) f[x][pos][sum] = ans;
    return ans;
}
ll calc(ll num) {
    int cnt = 0;
    memset(dp, - 1, sizeof(dp));
    memset(f, -1, sizeof(f));
    while (num) {
        digit[++cnt] = num % k;
        num /= k;
    }
    ll ans = dfs(cnt, 0, 1);
    for (int i = 2; i <= cnt; i++) {
        ans -= dfs1(cnt, 0, 1, i);
    }
    return ans;
    
}
int main() {
    in >> l >> r >> k;
    printf("%lld\n", calc(r) - calc(l - 1));
    return 0;
}
