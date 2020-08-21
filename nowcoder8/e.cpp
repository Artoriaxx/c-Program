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
ll f[N];
ll dp[N];
int a[N];
int main() {
    for (int l = 50; l < N; l++) {
        int mid = l + 1;
        int r = l + 2;
        for (int i = 1; i * l < N; i++) {
            for (int j = 3; j * mid + i * l < N; j++) {
                f[i*l+j*mid] += (j - 1) / 2;
            }
        }
        for (int i = 0; i * r < N; i++) {
            for (int j = 3; i * r + j * mid < N; j++) {
                f[i*r+j*mid] += (j - 1) / 2;
            }
        }
    }
    for (int l = 1; l < 50; l++) {
        memset(dp, 0, sizeof(dp));
        a[1] = l; a[2] = l + 1; a[3] = l + 2;
        int x = 3 * l + 3;
        dp[x] = 1;
        for (int i = 1; i <= 3; i++) {
            for (int j = x + a[i]; j < N; j++) {
                dp[j] += dp[j - a[i]];
            }
        }
        for (int i = 1; i < N; i++) f[i] += dp[i];
    }
    for (int i = 1; i < N; i++) f[i] += f[i - 1];
    int t; in >> t;
    int cse = 0;
    while (t--) {
        int l, r; in >> l >> r;
        printf("Case #%d: %lld\n", ++cse, f[r] - f[l - 1]);
    }
    return 0;
}
