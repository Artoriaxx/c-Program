/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-03-31 19:11:35
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-03-31 21:46:40
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
        int a, b, c, d;
        in >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        in >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool flag = true;
        if (a == b) {
            if (x1 == x2 && a != 0)  flag = false;
        }
        else if (a > b) {
            if (x - (a - b) < x1) flag = false;
        }
        else {
            if (x + b - a > x2) flag = false;
        }
        if (c == d) {
            if (y1 == y2 && c != 0) flag = false;
        }
        else if (c > d) {
            if (y - (c - d) < y1) flag = false;
        }
        else {
            if (y + d - c > y2) flag = false;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
