/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-04 12:05:21
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-04 12:26:20
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

const int N = 1050;
struct node {
    int s, e, id;
} a[N];
bool cmp(node x, node y) {
    return x.s == y.s ? x.e < y.e : x.s < y.s;
}
char ans[N];
int main() {
    int t; in >> t;
    int cse = 0;
    while (t--) {
        memset(ans, '\0', sizeof(ans));
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i].s >> a[i].e, a[i].id = i;
        bool flag = true;
        sort(a + 1, a + n + 1, cmp);
        int now1 = -1;
        int now2 = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i].s >= now1) {
                ans[a[i].id] = 'J';
                now1 = a[i].e;
            }
            else if (a[i].s >= now2) {
                ans[a[i].id] = 'C';
                now2 = a[i].e;
            }
            else {
                flag = false;
                break;
            }
        } 
        printf("Case #%d: ", ++cse);
        if (!flag) puts("IMPOSSIBLE");
        else printf("%s\n", ans + 1);
    }
    return 0;
}
