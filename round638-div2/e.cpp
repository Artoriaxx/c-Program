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

const int N = 550;
ll f[N][N];
int a[N], b[N];
int main() {
    int n, k; in >> n >> k;
    for (int i = 1; i <= n; i++) in >> a[i] >> b[i];
    ll sum = 0;
    ll ans = 0;
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] + b[i];
        for (int j = 0; j < k; j++) {
            if (f[i - 1][j] != -1) {
                int na = j + a[i];
                int nb = sum - f[i - 1][j] * k - na;
                f[i][na % k] = max(f[i][na % k], f[i - 1][j] + na / k + nb / k);
                ans = max(ans, f[i][na % k]);
                for (int x = 0; x < k && x <= a[i]; x++) {
                    if (b[i] >= k - x) {
                        na -= x;
                        nb -= k - x;
                        f[i][na % k] = max(f[i][na % k], f[i - 1][j] + na / k + nb / k + 1);
                        ans = max(ans, f[i][na % k]);
                        na += x;
                        nb += k - x;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
