/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-03-31 19:40:38
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-03-31 23:22:23
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

const int N = 600;
int a[N][N];
int main() {
    int k; scanf("%d", &k);
    int base = 1;
    while (base <= k) {
        base *= 2;
    }
    printf("2 3\n");
    printf("%d %d %d\n", k + base, base, base);
    printf("%d %d %d\n", k, k + base, k);
    
    return 0;
}
