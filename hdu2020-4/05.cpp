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

const int N = 1e5 + 50;
const ll p = 1e9 + 7;
char s[N][15];
bool isequal(char a[], char b[]) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    if (len1 != len2) return 0;
    for (int i = 0; i < len1; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}
ll f[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%s", s[i]);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!isequal(s[i], s[i - 1])) f[i] = (f[i - 1] + f[i - 2]) % p;
            else f[i] = f[i - 1];
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
