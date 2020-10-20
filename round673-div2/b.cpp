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
struct node {
    int val, id;
    bool operator < (const node &b) const {
        if (val == b.val) return id < b.id;
        return val < b.val;
    }
} a[N];
int cor[N];
int c[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, s; in >> n >> s;
        for (int i = 1; i <= n; i++) {
            in >> a[i].val;
            a[i].id = i;
            cor[i] = -1;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            if (cor[i] == -1) {
                int x = s - a[i].val;
                if (x == a[i].val) {
                    cor[i] = i & 1;
                    while (a[i+1].val == x) {
                        i++;
                        cor[i] = i & 1;
                    }
                }
                else {
                    int y = a[i].val;
                    cor[i] = 0;
                    while (a[i+1].val == y) {
                        i++;
                        cor[i] = 0;
                    }
                    node tmp;
                    tmp.val = x; tmp.id = 0;
                    int pos = lower_bound(a + 1, a + n + 1, tmp) - a;
                    while (a[pos].val == x) {
                        cor[pos] = 1;
                        pos++;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            c[a[i].id] = cor[i];
        }
        for (int i = 1; i <= n; i++) printf("%d ", c[i]);
        puts("");
    }
    return 0;
}
