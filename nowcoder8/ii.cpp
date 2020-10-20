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
int f[N];
int a[N], b[N], lis[N], vis[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    int _; in >> _;
    for (int t = 1; t <= _; t++) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) {
            in >> a[i] >> b[i];
            lis[i*2-1] = a[i], lis[i*2] = b[i];
        }
        sort(lis + 1, lis + 2 * n + 1);
        int m = unique(lis + 1, lis + 2 * n + 1) - lis - 1;
        for (int i = 1; i <= m; i++) f[i] = i, vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(lis + 1, lis + m + 1, a[i]) - lis;
            b[i] = lower_bound(lis + 1, lis + m + 1, b[i]) - lis;
            int x = find(a[i]), y = find(b[i]);
            if (x == y) vis[x] = vis[y] = 1;
            else {
                f[y] = x;
                if (vis[y]) vis[x] = 1;
            }
        }
        int ans = m;
        for (int i = 1; i <= m; i++) {
            f[i] = find(f[i]);
            if (f[i] == i && !vis[i]) ans--;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
