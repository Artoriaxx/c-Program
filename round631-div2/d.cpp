/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-03 21:49:55
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-04 00:46:01
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

const int N = 2e5 + 50;
ll f[100][100];
int main() {
    int t; in >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        ll d, m;
        in >> d >> m;
        ll ans = 0;
        ll base = 1;
        ll pos = 1;
        int mx = 1;
        while ((base << 1) <= d) {
            base <<= 1;
            pos++;
            mx++;
        }
        while (base) {
            ll tmp = base;
            ans = (ans + min((tmp << 1) - 1, d) - tmp + 1) % m;
            ll now = (min((tmp << 1) - 1, d) - tmp + 1) % m;
            f[pos][1] = now;
            int x = 2;
            while ((tmp << 1) <= d) {
                tmp <<= 1;
                
                for (int i = pos + 1; i <= mx; i++) {
                    f[pos][x] = (f[pos][x] + f[i][x - 1]) % m;
                }
                f[pos][x] = f[pos][x] * f[pos][1] % m;
                ans = (ans + f[pos][x]) % m;
                x++;

                now = now * ((min((tmp << 1) - 1, d) - tmp + 1) % m) % m;
                
            }
            base >>= 1;
            pos--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
