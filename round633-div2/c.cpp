/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-12 21:38:16
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-12 22:35:58
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
ll a[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] < a[i - 1]) {
                ll x = a[i - 1] - a[i];
                int cnt = 0;
                while (x) {
                    cnt++;
                    x >>= 1;
                }
                ans = max(ans, cnt);
                a[i] = a[i - 1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
