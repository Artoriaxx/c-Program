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
char s[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n, m;
int vis[N][N];
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '#' && !vis[x][y];
}
void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) dfs(nx, ny);
    }
}
int numx[N], numy[N];
int main() {
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') numx[i]++, numy[j]++;
        }
    }

    bool f1 = true;
    for (int i = 1; i <= n; i++) {
        bool f2 = false, f3 = false, f4 = false, f5 = false;
        for (int j = 1; j <= m; j++) {
            if (numy[j] == n) f5 = true;
            if (s[i][j] == '#') {
                f4 = true;
                if (!f2) f2 = true;
                if (f3) f1 = false;
            }
            else {
                if (f2) f3 = true;
            }
        }
        if (!f4 && !f5) f1 = false;
    }
    for (int j = 1; j <= m; j++) {
        bool f2 = false, f3 = false, f4 = false, f5 = false;
        for (int i = 1; i <= n; i++) {
            if (numx[i] == m) f5 = true;
            if (s[i][j] == '#') {
                f4 = true;
                if (!f2) f2 = true;
                if (f3) f1 = false;
            }
            else {
                if (f2) f3 = true;
            }
        }
        if (!f4 && !f5) f1 = false;
    }
    if (!f1) puts("-1");
    else {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j] && s[i][j] == '#') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
