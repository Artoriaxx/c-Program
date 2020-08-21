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

const int N = 150;
int a[N];
int main() {
    int n; in >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        in >> a[i];
        if (a[i] > mx) mx = a[i]; 
    }
    for (int i = 1; i <= n; i++) {
        int num = ceil(1.0 * 50 * a[i] / mx);
        putchar('+');
        for (int j = 1; j <= num; j++) putchar('-');
        putchar('+');
        puts("");
        if (a[i] == mx) {
            putchar('|');
            for (int j = 1; j < num; j++) {
                putchar(' ');
            }
            putchar('*');
            putchar('|');
        }
        else {
            putchar('|');
            for (int j = 1; j <= num; j++) {
                putchar(' ');
            }
            putchar('|');
        }
        printf("%d\n", a[i]);
        putchar('+');
        for (int j = 1; j <= num; j++) putchar('-');
        putchar('+');
        puts("");
    }
    
    return 0;
}