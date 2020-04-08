/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-04 11:34:38
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-04 11:58:34
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

const int N = 105;
char s[N];
string ans1[N], ans2[N];
char tmp[N];
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        cse++;
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        strcpy(tmp + 1, s + 1);
        for (int i = 1; i <= n; i++) {
            ans1[i] = "";
            ans2[i] = "";
        }
        for (int i = 1; i <= n; i++) {
            
            int x = s[i] - '0';
            for (int j = 1; j <= x; j++) {
                ans1[i] = ans1[i] + "(";
            }
            
            for (int j = i; j <= n; j++) {
                if (s[j] - '0' >= x) {
                    s[j] = s[j] - x;
                }
                else {
                    
                    int cnt = x - (s[j] - '0');
                    s[j] = '0';
                    for (int k = 1; k <= cnt; k++) {
                        ans2[j - 1] = ans2[j - 1] + ")";
                    }
                    x -= cnt;
                }
            }
            for (int i = 1; i <= x; i++) {
                ans2[n] = ans2[n] + ")";
            }
        }
        printf("Case #%d: ", cse);
        for (int i = 1; i <= n; i++) {
            cout << ans1[i] << tmp[i] << ans2[i];
        }
        puts("");
    }
    return 0;
}
