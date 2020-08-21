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

const int N = 5050;
int num[4];
int c[N];
bool flag = true;
int x[N][2];
int cnt;
vector<int> G[N];
int block[N];
int res[N];
bool dfs(int u, int f, int ty) {
    c[u] = ty;
    x[cnt][ty]++;
    block[u] = cnt;
    for (auto v : G[u]) {
        if (v == f) continue;
        if (c[v] == -1) {if (!dfs(v, u, !ty)) return false;}
        else if (c[u] == c[v]) return false;
    }
    return true;
}
int f[N][N];
int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= 3; i++) in >> num[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(c, -1, sizeof(c));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (c[i] == -1) {
            cnt++;
            if (!dfs(i, 0, 0)) {
                puts("NO");
                return 0;
            }
            for (int t = 0; t < 2; t++) {
                for (int j = x[cnt][t]; j <= num[2]; j++) {
                    f[cnt][j] |= f[cnt - 1][j - x[cnt][t]];
                }
            }
        }
    }
    if (!f[cnt][num[2]]) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = cnt; i >= 1; i--) {
        res[i] = f[i - 1][num[2] - x[i][0]];
        if (res[i]) num[2] -= x[i][0];
        else num[2] -= x[i][1];
    }
    for (int i = 1; i <= n; i++) {
        if (res[block[i]]) {
            if (c[i] == 0) putchar('2');
            else if (num[3] > 0) {
                num[3]--;
                putchar('3');
            }
            else putchar('1');
        }
        else {
            if (c[i] == 1) putchar('2');
            else if (num[3] > 0) {
                num[3]--;
                putchar('3');
            }
            else putchar('1');
        }
    }
    return 0;
}