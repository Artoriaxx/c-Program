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
#define int long long
const int N = 2e5 + 50;
const int p = 1e9 + 7;
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}
int pre[N];
signed main() {
    int t, k, x; in >> t >> k >> x;
    for (int i = 1; i <= 2e5; i++) pre[i] = (pre[i-1] + qpow(i, k)) % p;
    for (int i = 1; i <= 2e5; i++) pre[i] = qpow(pre[i], x);
    while (t--) {
        int n; in >> n;
        int ans = 0;
        for (int j = 2; j * j <= n; j++) {
            ans = (ans + 1ll * pre[n] * j % p * j % p) % p;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
