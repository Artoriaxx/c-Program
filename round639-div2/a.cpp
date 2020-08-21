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
ll f[N];
int main() {
    int t; in >> t;
    f[1] = 2;
    int cnt = 1;
    for (int i = 2; i < N; i++) {
        f[i] = f[i - 1] + i * 3 - 1;
        if (f[i] > 1e9) {
            cnt = i;
            break;
        }
    }
    while (t--) {
        int n;
        in >> n;
        int ans = 0;
        while (n > 0) {
            if (n == 1) break;
            auto x = lower_bound(f + 1, f + cnt + 1, n) - f;
            if (f[x] > n) x--;
            n -= f[x];
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
