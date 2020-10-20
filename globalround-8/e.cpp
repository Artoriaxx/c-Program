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
int dis[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) {
            dis[i] = 1;
            G[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v; in >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == 3) {
                ans.push_back(i);
                continue;
            }
            for (int v : G[i]) {
                dis[v] = max(dis[v], dis[i] + 1);
            }
        }
        printf("%d\n", ans.size());
        for (int i : ans) printf("%d ", i);
        puts("");
    }
    return 0;
}
