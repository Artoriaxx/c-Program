/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-08 21:13:30
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-08 22:51:33
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
int a[N], b[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 1; i <= n; i++) in >> b[i];
        if (a[1] != b[1]) {
            puts("NO");
            continue;
        }
        bool flag = true;
        bool flag1 = false, flag2 = false;
        if (a[1] == 1) flag1 = true;
        if (a[1] == -1) flag2 = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] < b[i]) {
                if (!flag1) {
                    flag = false;
                    break;
                }
            }
            else if (a[i] > b[i]) {
                if (!flag2) {
                    flag = false;
                    break;
                }
            }
            if (a[i] == 1) flag1 = true;
            if (a[i] == -1) flag2 = true;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
