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

const int N = 2e5 + 50;
int ind[N];
vector<int> G[N];
vector<int> s;
void dfs(int u, int f) {
    if (ind[u] == 1) s.push_back(u);
    for (auto v : G[u]) {
        if (v != f) dfs(v, u);
    }
}
int main() {
    int n; in >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ind[u]++; ind[v]++;
    }
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        if (ind[i] > 1) rt = i;
    }
    dfs(rt, 0);
    int m = s.size();
    printf("%d\n", (m + 1) / 2);
    for (int i = 1; i * 2 <= m; i++) printf("%d %d\n", s[i - 1], s[i - 1 + (m + 1) / 2]);
    if (m & 1) printf("%d %d\n", rt, s[(m + 1) / 2 - 1]);
    return 0;
}
