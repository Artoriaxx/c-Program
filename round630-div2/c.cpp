/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-03-31 19:39:44
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-03-31 23:00:32
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
char s[N];
int f[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int num[N][30];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            for (int j = 0; j < 30; j++) {
                num[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            
            int x = find(i);
            int y = find(n - i + 1);
            if (x != y) f[x] = y;
            
        }
        for (int i = 1; i <= n - k; i++) {
            
            int x = find(i);
            int y = find(i + k);
            if (x != y) f[x] = y;
        }
        for (int i = 1; i <= n; i++) {
            int x = find(i);
            num[x][0]++;
            num[x][s[i] - 'a' + 2]++;
            num[x][1] = max(num[x][1], num[x][s[i] - 'a' + 2]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == i) {
                ans += num[f[i]][0] - num[f[i]][1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
