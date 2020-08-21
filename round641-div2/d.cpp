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
int a[N], f[N];
int main() {
    int t; in >> t;
    while (t--) {
        bool f1 = false, f2 = false;
        int n, k;
        in >> n >> k;
        for (int i = 1; i <= n; i++) in >> a[i], f[i] = 0;
        f[0] = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) f1 = true;
        }
        if (!f1) puts("no");
        else {
            if (n == 1) {
                puts("yes");
                continue;
            }
            for (int i = 1; i <= n; i++) {
                f[i] = max(f[i - 1], 0);
                if (a[i] >= k) f[i]++; else f[i]--;
                if (f[i] >= 1 && f[i - 1] >= 0) f2 = true;
            }
            if (f2) puts("yes");
            else puts("no");
        }
    }
    return 0;
}
