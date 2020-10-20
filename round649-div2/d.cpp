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
vector<int> G[N];
int pos;
int dep[N];
int pre[N];
int mn = 1e9;
void dfs(int u, int fa, int d) {
    pre[u] = fa;
    dep[u] = d;
    for (int v : G[u]) {
        if (v == fa) continue;
        if (!dep[v]) dfs(v, u, d + 1);
        else if (dep[u] - dep[v] > 0 && dep[u] - dep[v] + 1 < mn){
            mn = dep[u] - dep[v] + 1;
            pos = u;
        }
    }
}
int main() {
    int n, m, k; in >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v; in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, 1);
    if (m == n - 1) {
        vector<int> res[2];
        for (int i = 1; i <= n; i++) {
            res[dep[i] & 1].push_back(i);
        }
        puts("1");
        int sz = (k + 1) / 2;
        if (res[0].size() < res[1].size()) {
            for (int i = 0; i < sz; i++) printf("%d ", res[1][i]);
        }
        else {
            for (int i = 0; i < sz; i++) printf("%d ", res[0][i]);
        }
        return 0;
    }
    if (mn <= k) {
        puts("2");
        printf("%d\n", mn);
        while (mn--) {
            printf("%d ", pos);
            pos = pre[pos];
        }
    }
    else {
        puts("1");
        for (int i = 0; i < (k + 1) / 2; i++) {
            printf("%d ", pos);
            pos = pre[pre[pos]];
        }
    }
    return 0;
}
