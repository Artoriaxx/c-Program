/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-03 21:49:36
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-03 22:39:29
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
int a[N];
int val[1200];
int main() {
    int t; in >> t;
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        memset(val, 0, sizeof(val));
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), val[a[i]]++;
        int ans = 0;
        for (int i = 1; i <= 210; i++) {
            if (val[i] == 0) {
                if (x == 0) {
                    ans = i - 1;
                    break;
                }
                else {
                    x--;
                }
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}
