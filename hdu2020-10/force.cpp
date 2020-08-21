#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef _WIN32
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

const int N = 5050;
const ll mod = 1e9 + 7;
int b[N];
int a[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int cnt = 0;
        for (int i = 1; i < n; i++) in >> b[i];
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        do {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (b[i]) {
                    if (a[i] < a[i + 1]) {
                        flag = false;
                        break;
                    }
                } 
                else {
                    if (a[i] > a[i + 1]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                for (int i = 1; i <= n; i++) {
                    printf("%d ", a[i]);
                }
                cnt++;
                puts("");
            }
        } while (next_permutation(a + 1, a + n + 1));

        printf("%d\n", cnt);
    }
    return 0;
}
