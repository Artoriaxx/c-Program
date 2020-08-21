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
int a[N];
ll f[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        sort(a + 1, a + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i+=2) {
            ans += a[i + 1] - a[i];
        }
        memset(f, -1, sizeof(f));
        for (int i = 4; i <= n; i++) {
            if (i - 4 >= 0 && f[i - 4] != -1) {
                f[i] = f[i - 4] + min(a[i] - a[i - 2] + a[i - ]) 
                
            }
        }
        // ll res1 = 0, res2 = 0;ll res;
        // for (int i = 2; i <= n - 1; i+=2) {
        //     res1 += a[i + 1] - a[i];
        // }
        // res1 += a[n] - a[1];
        // for (int i = 1; i <= n / 2; i++) {
        //     res2 += a[i + n / 2] - a[i];
        // }
        // if (n % 4 == 0) {
        //     ll res3 = 0;
        //     for (int i = 1; i <= n; i++) {
        //         if (i % 4 == 1 || i % 4 == 2) {
        //             res3 += a[i + 2] - a[i];
        //         }
        //     }
        //     res = min(res1, res3);
        //     res3 = 0;
        //     for (int i = 1; i <= n; i++) {
        //         if (i % 4 == 1) {
        //             res3 += a[i + 3] - a[i];
        //         }
        //         if (i % 4 == 2) {
        //             res3 += a[i + 1] - a[i];
        //         }
        //     }
        //     res = min(res1, res3);
        // }
        // else res = min(res1, res2);
        // if (n % 4 == 2) {
        //     for (int i = 4; i <= n; i+=4) {
        //         pre1[i] = pre1[i - 4] + min(a[i] - a[i - 2] + a[i - 1] - a[i - 3], a[i] - a[i - 3] + a[i - 1] - a[i - 2]); 
        //     }
        //     for (int i = 10; i <= n; i+=4) {
        //         pre2[i] = pre2[i - 4] + min(a[i] - a[i - 2] + a[i - 1] - a[i - 3], a[i] - a[i - 3] + a[i - 1] - a[i - 2]); 
        //     }
        //     for (int i = 1; i <= n - 5; i += 4) {
        //         ll now = 0;
        //         ll tmp = a[i + 3] - a[i] + a[i + 4] - a[i + 1] + a[i + 5] - a[i + 2];
        //         tmp = min(tmp, a[i + 5] - a[i] + a[i + 2] - a[i + 1] + a[i + 4] - a[i + 3]);
        //         tmp = min(tmp, a[i + 2] - a[i] + a[i + 4] - a[i + 1] + a[i + 5] - a[i + 3]);
        //         tmp = min(tmp, )
        //         now += ;
        //         now += pre1[i - 1];
        //         now += pre2[n] - pre2[min(n, i + 5)];
        //         res = min(res, now);
        //     }
        // }
        // ans += res;
        printf("%lld\n", ans);
    }
    return 0;
}