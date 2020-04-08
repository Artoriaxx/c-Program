/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-03 21:49:42
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-03 23:47:01
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
int l[N];
int main() {
    int n, m; in >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= m; i++) in >> l[i], sum += l[i];
    if (sum < n) {
        puts("-1");
        return 0;
    }
    bool flag = true;
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        mx = max(mx, i + l[i] - 1);
        if (l[i] > n - i + 1) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        puts("-1");
    }
    else {
        
        int now = 1;
        int cnt = n - mx;
        for (int i = 1; i <= m; i++) {
            printf("%d ", now);
            if (l[i] > cnt) {
                now += cnt + 1;
                cnt = 0;
            }
            else {
                now += l[i];
                cnt = cnt - (l[i] - 1);
            }
        }
        

    }
    return 0;
}
