/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-11 08:47:16
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-11 08:47:39
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

const int N = 350;
ll a[N];
int main() {
    int t; in >> t;
    int cse = 0;
    while (t--) {
        int n, d;
        in >> n >> d;
        for (int i = 1; i <= n; i++) in >> a[i];
        sort(a + 1, a + n + 1);
        int ans = d - 1;
        
        printf("Case #%d: %d\n", ++cse, ans);
    }
    return 0;
}
