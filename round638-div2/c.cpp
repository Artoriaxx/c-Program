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
int f[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        
        scanf("%s", s + 1);
        sort(s + 1, s + n + 1);
        if (k == 1) {
            puts(s + 1);
            continue;
        }
        
        f[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            f[i] = f[i + 1];
            if (s[i] != s[i + 1]) f[i]++;
        }
        bool flag = false;
        for (int i = 1; i < k; i++) {
            if (s[i] != s[k]) flag = true;
        }
        if (flag) {
            putchar(s[k]);
        }
        else {
            putchar(s[k]);
            if (f[k + 1] > 1) {
                for (int i = k + 1; i <= n; i++) putchar(s[i]);
            }
            else {
                for (int i = k + 1; i <= n; i++) if (i % k == 1) putchar(s[i]);
            }
        }
        puts("");
    }
    return 0;
}
