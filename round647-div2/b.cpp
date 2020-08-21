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
int a[N];
int b[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
        }
        sort(a + 1, a + n + 1);
        bool flag = false;
        for (int i = 1; i <= 2048; i++) {
            for (int j = 1; j <= n; j++) {
                b[j] = a[j] ^ i;
            }
            sort(b + 1, b + n + 1);
            bool f1 = true;
            for (int j = 1; j <= n; j++) {
                if (b[j] != a[j]) {
                    f1 = false;
                    break;
                }
            }
            if (f1) {
                flag = true;
                printf("%d\n", i);
                break;
            }
        }
        if (!flag) puts("-1");
    }
    return 0;
}
