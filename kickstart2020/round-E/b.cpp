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
int ans[N];
int main() {
    int tc; in >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, a, b, c; in >> n >> a >> b >> c;
        int h = n;
        for (int i = 1; i <= 3 * n; i++) ans[i] = 0;
        int cnt = 0;
        for (int i = 1; i <= c; i++) {
            ans[i + n] = h;
            cnt++;
        }
        a -= c; b -= c;
        int cntl = 0, cntr = 0;
        int tmp = h;
        for (int i = 1; i <= a; i++) {
            h--;
            ans[a - i + 1] = h;
            cnt++;
            cntl++;
        }
        h = tmp;
        for (int i = 1; i <= b; i++) {
            h--;
            ans[3 * n - (b - i)] = h;
            cnt++;
            cntr++;
        }
        if (cnt > n || a < 0 || b < 0) {
            //puts("-1");
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
        else {
            
            if (cntl == 0 && cntr == 0 && cnt == 1 && n - cnt > 0) {
                
                printf("Case #%d: IMPOSSIBLE\n", t);
                continue;
            }
            printf("Case #%d:", t);
            for (int i = 1; i <= 3 * n; i++) {
                if (i == n + 1) {
                    if (cnt - cntl - cntr > 1) {
                        printf(" %d", ans[i]);
                        h = 1;
                        for (int j = 1; j <= n - cnt; j++) {
                            printf(" %d", h);
                        }
                        continue;
                    }
                    if (cntr == 0) {
                        h = 1;
                        for (int j = 1; j <= n - cnt; j++) {
                            printf(" %d", h);
                        }
                        printf(" %d", ans[i]);
                    }
                    else {
                        printf(" %d", ans[i]);
                        h = 1;
                        for (int j = 1; j <= n - cnt; j++) {
                            printf(" %d", h);
                        }

                    }
                    continue;              
                }
                if (ans[i] != 0) printf(" %d", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
