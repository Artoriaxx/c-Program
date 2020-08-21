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
struct node {
    int l, r;
    char val;
} f[N];
int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int m; scanf("%d", &m);
    int now = 0;
    while (m--) {
        char ch[2];
        scanf("%s", ch);
        int x;
        scanf("%d", &x);
        if (ch[0] == 'M') {
            now += x;
            if (now >= len) now -= len;
            if (now <= -len) now += len; 
        }
        else {
            if (now < 0) {
                now = -now;
                if (x <= now) {
                    putchar(s[len - now + x]);
                }
                else {
                    x -= now;
                    putchar(s[x]);
                }
                now = -now;
            }
            else {
                if (x <= (len - now)) {
                    putchar(s[now + x]);
                }
                else {
                    x -= (len - now);
                    putchar(s[x]);
                }
            }
            puts("");
        }
    }
    return 0;
}
