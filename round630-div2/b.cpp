/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-03-31 19:39:22
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-03-31 22:31:45
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
int cor[N];
int is[N], prime[N];
int a[N];
int f[N];
int vis[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
    int cnt = 0;
    for (int i = 2; i <= 1050; i++) {
        if (!is[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= 1050; j++) {
            is[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 1; i <= n; i++) cor[i] = 0, f[i] = i, vis[i] = 0;
        int tot = 0;
        for (int i = 1; i <= cnt; i++) {
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (!cor[j]) {
                    if (a[j] % prime[i] == 0) {
                        if (!flag) {
                            flag = true;
                            tot++;
                        }
                        cor[j] = tot;
                    }
                }
            }
        }
        printf("%d\n", tot);
        for (int i = 1; i <= n; i++) {
            printf("%d ", cor[i]);
        }
        puts("");
    }
    return 0;
}