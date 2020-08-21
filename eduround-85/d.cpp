/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-10 22:26:35
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-11 00:09:51
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
int main() {
    int t; in >> t;
    while (t--) {
        ll n, l, r;
        in >> n >> l >> r;
        ll now = 1;
        ll sum = 0;
        while (sum + (n - now) * 2 < l && now < n) {
            sum += (n - now) * 2;
            now++;
        }
        if (now == n && sum < l) {
            puts("1");
            continue;
        }
        ll begin = now;
        ll turn = now;
        ll cnt = 1;
        for (ll i = sum + 1; i <= l; i++) {
            if (cnt & 1) {
                begin = now;
            }
            else {
                begin = ++turn;
            }
            cnt++;
        }
        ll ans = begin;
        for (ll i = l; i <= r; i++) {
            printf("%lld ", ans);
            if (ans == now) {
                ans = ++turn;
            }
            else {
                if (turn == n) {
                    now++;
                    turn = now;
                    if (now == n) {
                        now = 1;
                    }
                }
                ans = now;
            }
        }
        puts("");
        
    }
    return 0;
}
