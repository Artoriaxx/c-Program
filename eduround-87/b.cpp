#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
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
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int p1, p2, p3;
        p1 = p2 = p3 = -1;
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                p1 = i;
                if (p2 != -1 && p3 != -1) {
                    int mn = min(p2, p3);
                    ans = min(ans, i - mn + 1);
                }
            }
            if (s[i] == '2') {
                p2 = i;
                if (p1 != -1 && p3 != -1) {
                    int mn = min(p1, p3);
                    ans = min(ans, i - mn + 1);
                }
            }
            if (s[i] == '3') {
                p3 = i;
                if (p2 != -1 && p1 != -1) {
                    int mn = min(p1, p2);
                    ans = min(ans, i - mn + 1);
                }
            }
        }
        if (ans == (int)1e9) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
