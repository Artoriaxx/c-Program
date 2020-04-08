/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-01 16:20:46
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-01 17:56:14
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ios {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x) {
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
int a[N];
int s[N][10];
int pos[N];
bool cmp(int x, int y) {
    return a[x] > a[y]; 
}
ll dp[N][(1 << 8)];
int main() {
    int n, p, k; in >> n >> p >> k;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            in >> s[i][j];
        }
    }
    for (int i = 1; i <= n; i++) pos[i] = i;
    memset(dp, -1, sizeof(dp));
    sort(pos + 1, pos + n + 1, cmp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << p); j++) {
            int tmp = j;
            int c = 0;
            while (tmp) {
                if (tmp & 1) c++;
                tmp >>= 1;
            }
            int x = i - 1 - c;
            if (x < k) {
                if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j] + a[pos[i]];
            }
            else {
                if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j];
            }
            for (int k = 0; k < p; k++) {
                if (j & (1 << k)) {
                    if (dp[i - 1][j - (1 << k)] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - (1 << k)] + s[pos[i]][k + 1]);
                }
            }
        }

    }
    printf("%lld\n", dp[n][(1 << p) - 1]);
    return 0;
}
