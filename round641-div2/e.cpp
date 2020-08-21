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
ll f[N][N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int vis[N][N];
int n, m, t;
typedef pair<int, int> pii;
int check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
    
    scanf("%d%d%d", &n, &m, &t);
    memset(f, -1, sizeof(f));
    queue<pii> q;
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (check(nx, ny)) {
                    if (s[i][j] == s[nx][ny]) {
                        f[i][j] = 1;
                        q.push(pii(i, j));
                    }
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && f[nx][ny] == -1) {
                f[nx][ny] = f[x][y] + 1;
                q.push(pii(nx, ny));
            }
        }
    }
    while (t--) {
        int x, y; ll p;
        scanf("%d%d%lld", &x, &y, &p);
        if (p < f[x][y] || f[x][y] == -1) putchar(s[x][y]), puts("");
        else {
            p -= f[x][y];
            if (p & 1) {
                if (s[x][y] == '1') puts("1");
                else puts("0");
            }
            else {
                if (s[x][y] == '1') puts("0");
                else puts("1");
            }
        }

    }
    return 0;
}
