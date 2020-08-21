/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-10 22:26:27
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-10 23:03:35
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

const int N = 3e5 + 50;
ll a[N], b[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i] >> b[i];
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int nx = i + 1;
            if (nx > n) nx -= n;
            if (a[nx] > b[i]) {
                sum += a[nx] - b[i];
                a[nx] = b[i];
            }
        }
        ll mn = 1e18;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, a[i]);
        }
        sum += mn;
        printf("%lld\n", sum);
    }
    return 0;
}
