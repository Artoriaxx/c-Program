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
int a[N];
double f[20][N];
vector<int> G[N];
int d[N];
int main() {
    f[1][2] = 1.0;
    int n; in >> n;
    for (int i = 1; i < n; i++) {
        int u, v; in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    for (int i = 3; i < N; i++) {
        for (int j = 1; j <= n; j++) {
            for (int v : G[j]) {
                f[j][i] += f[v][i - 1] * 1.0 / (double)(d[v] + 1);
            }
            f[j][i] += f[j][i - 1] * 1.0 / (double)(d[j] + 1);
        }
    }

    printf("%lf", f[1][N-1]);
    return 0;
}
