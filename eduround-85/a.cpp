/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-10 22:25:40
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-10 22:51:37
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
int p[N], c[N];
int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> c[i];
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (p[i] < c[i]) flag = false;
        }
        for (int i = 2; i <= n; i++) {
            if (p[i] < p[i - 1] || c[i] < c[i - 1] || (p[i] - p[i - 1]) < (c[i] - c[i - 1])) {
                flag = false;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
