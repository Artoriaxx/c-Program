/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-12 21:38:24
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-13 11:59:42
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
ll dx[4] = {0,2,3,1};
int main() {
    int t; in >> t;
    ll n = 0;
    while (t--) {
        in >> n;
        ll y = n % 3;
        ll base = 4;
        ll cnt = 1;
        while ((base - 1) < n) {
            base <<= 2;
            cnt++;
        }
        base >>= 2;
        ll x = n - base + 1;
        x = (x - 1) / 3 + 1;
        x--;
        ll ans1 = base + x;
        ll ans2 = base << 1;
        cnt = 0;
        while (x) {
            ans2 += dx[x % 4] << (2ll * cnt);
            cnt++;
            x >>= 2;
        }
        ll ans3 = ans1 ^ ans2;
        if (y == 1) printf("%lld\n", ans1);
        if (y == 2) printf("%lld\n", ans2);
        if (y == 0) printf("%lld\n", ans3);
    }
    
    return 0;
}
