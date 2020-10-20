#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
#define pii pair<int, int>
pii ans[N];
int main() {
    int n; in >> n;
    printf("%d\n", 7 * n + 8);
    int cnt = 0;
    for (int i = 3; i <= 2 * n + 1; i+=2) {
        printf("1 %d\n", i);
        cnt++;
        // ans[cnt] = pii(1, i);
    }
    for (int i = 2; i <= 2 * n + 2; i++) {
        printf("2 %d\n", i);
        cnt++;
        // ans[cnt] = pii(2, i);
    }
    for (int i = 3; i <= 2 * n + 1; i+=2) {
        printf("3 %d\n", i);
        cnt++;
        // ans[cnt] = pii(3, i);
    }
    for (int i = 1; i <= 2 + 2 * n; i+=2) {
        if (i == n) {
            printf("0 %d\n", 2 * n + 1);
            printf("0 %d\n", 2 * n + 2);
            printf("0 %d\n", 2 * n + 3);
            printf("1 %d\n", 2 * n + 3);
            printf("2 %d\n", 2 * n + 3);
            // ans[cnt+1] = pii(0, 2 * n + 1);
            // ans[cnt+2] = pii(0, 2 * n + 2);
            // ans[cnt+3] = pii(0, 2 * n + 3);
            // ans[cnt+4] = pii(1, 2 * n + 3);
            // ans[cnt+5] = pii(2, 2 * n + 3)
            cnt+=5;
        }
        else if (i == n + 1) {
            printf("2 %d\n", 2 * n + 3);
            printf("3 %d\n", 2 * n + 3);
            printf("4 %d\n", 2 * n + 3);
            printf("4 %d\n", 2 * n + 2);
            printf("4 %d\n", 2 * n + 1);
            cnt+=5;
        }
        else if (i == 2 * n + 1) {
            printf("4 3\n");
            printf("4 2\n");
            printf("4 1\n");
            printf("3 1\n");
            printf("2 1\n");
            cnt+=5;
        }
        else if (i <= n) {
            printf("0 %d\n", 2 * i + 1);
            printf("0 %d\n", 2 * i + 2);
            printf("0 %d\n", 2 * i + 3);
            cnt+=3;
        }
        else if (i >= n + 2) {
            int x = 2 * n - i + 2;
            printf("4 %d\n", 2 * x + 1);
            printf("4 %d\n", 2 * x);
            printf("4 %d\n", 2 * x - 1);
            cnt+=3;
        }
    }
    //printf("%d\n", cnt);
    return 0;
}
