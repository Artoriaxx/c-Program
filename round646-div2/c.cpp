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

const int N = 1050;
vector<int> G[N];
int deg[N], dep[N];
void dfs(int x, int f, int d) {
    dep[d]++;
    for (int v : G[x]) {
        if (v == f) continue;
        dfs(v, x, d + 1);
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, x; in >> n >> x;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            deg[i] = 0;
            dep[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v; in >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        if (deg[x] == 1 || deg[x] == 0) {
            puts("Ayush");
            continue;
        }
        if (n % 2 == 0) puts("Ayush");
        else puts("Ashish");
    }
    return 0;
}
