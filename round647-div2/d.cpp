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

const int N = 5e5 + 50;
vector<int> G[N];
vector<int> cor[N];
int num[N];
int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int x; in >> x;
        cor[x].push_back(i);
        num[i] = 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int u : cor[i]) {
            if (num[u] != i) {
                puts("-1");
                return 0;
            }
            for (int v : G[u]) {
                if (num[v] == num[u]) {
                    num[v] = num[u] + 1;
                }
            }
            ans.push_back(u);
        }
    }
    for (int res : ans) printf("%d ", res);
    return 0;
}
