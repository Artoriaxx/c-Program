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
int c0[N], c1[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int m = 32;
        for (int i = 0; i < 40; i++) c0[i] = c1[i] = 0;

        for (int i = 1; i <= n; i++) {
            int x; in >> x;
            for (int j = 0; j < m; j++) {
                if ((x >> j) & 1) c1[j]++;
                else c0[j]++;
            }
        }
        // for (int i = 0; i < 5; i++) {
        //     printf("%d %d\n", c0[i], c1[i]);
        // }
        int s = 0;
        for (int i = m; i >= 0; i--) {
            if (c1[i] % 2 == 0) continue;
            int x = (c1[i] - 1) / 2;
            if (x % 2 == 0) s = 1;
            if (x % 2 == 1) {
                if (n & 1) s = -1;
                else s = 1;
            }
            break;
        }
        if (s == 0) puts("DRAW");
        else if (s == 1) puts("WIN");
        else puts("LOSE");
    }
    return 0;
}
