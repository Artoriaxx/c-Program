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
char a[105][1005];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        for (int i = 0; i < n; i++) scanf("%s", a[i]);
        ll ans = 0;
        if (x * 2 <= y) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '.') ans += x;
                }
            }
            printf("%lld\n", ans);
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    if (j + 1 < m && a[i][j + 1] == '.') {
                        j++;
                        ans += y;
                    }
                    else ans += x;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
