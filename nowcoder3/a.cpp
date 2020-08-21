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

const int N = 2e6 + 50;
char s[N];
int f[N];
int mn[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        scanf("%s", s + 1);
        int now = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                if (now > 0) {
                    now--; ans++;
                }
            }
            if (s[i] == '1') {
                now++;
            }
            if (s[i] == '2') {
                ans++;
            }
            if (s[i] == '3') {
                ans++;
            }
            f[i] = now;
        }
        if (now > 0) {
            for (int i = 1; i <= n + 1; i++) mn[i] = 1e9;
            for (int i = n; i >= 1; i--) {
                mn[i] = min(mn[i + 1], f[i]);
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (mn[i] - cnt - 2 >= 0) {
                    ans++;
                    cnt += 2;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;

}
