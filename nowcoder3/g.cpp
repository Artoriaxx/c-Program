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

const int N = 8e5 + 50;
vector<int> G[N];
int f[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(vector<int> &x, vector<int> &y) {
    if (x.size() < y.size()) swap(x, y);
    for (auto e : y) x.push_back(e);
    y.clear();
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) G[i].clear(), f[i] = i;
        for (int i = 1; i <= m; i++) {
            int x, y; in >> x >> y; x++; y++;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int q; in >> q;
        while (q--) {
            int o; in >> o; o++;
            if (find(o) != o) continue;
            vector<int> tmp = G[o];
            G[o].clear();
            for (auto nx : tmp) {
                int y = find(nx);
                if (y == o) continue;
                f[y] = o;
                merge(G[o], G[y]);
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", find(i) - 1);
        }
        puts("");
    }
    return 0;
}
