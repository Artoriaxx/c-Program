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
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
struct node {
    int u, v, w;
    node() {}
    node(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator < (const node &b) const {
        return w < b.w;
    }
} edge[N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                edge[++cnt] = node(i, j, (i + 1) * (j + 1) / gcd(i + 1, j + 1));
            }
        }
        for (int i = 1; i <= n; i++) f[i] = i;
        sort(edge + 1, edge + cnt + 1);
        ll ans = 0;
        for (int i = 1; i <= cnt; i++) {
            int u = edge[i].u, v = edge[i].v;
            u = find(u), v = find(v);
            if (u == v) continue;
            else {
                f[u] = v;
                printf("%d %d %d %d %d\n",edge[i].w);
                ans += edge[i].w;
            }
        }
        puts("");
        printf("%lld\n", ans);
    }
    return 0;
}
