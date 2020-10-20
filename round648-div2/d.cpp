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

const int N = 55;
char s[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
bool check1(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != 'B' && s[x][y] != 'G';
}
bool check2(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#';
}
#define pii pair<int, int>
int can[N][N];
pii pre[N][N];
int vis[N][N];
bool work(int x, int y) {
    queue<pii> q;
    q.push(pii(x, y));
    vis[x][y] = 1;
    pre[x][y] = pii(x, y);
    vector<pii> tmp;
    tmp.push_back(pii(x, y));
    while (!q.empty()) {
        pii now = q.front(); q.pop();
        if (can[now.first][now.second]) {
            while (pre[now.first][now.second] != now) {
                now = pre[now.first][now.second];
                can[now.first][now.second] = 1;
            }
            for (pii cc : tmp) {
                vis[cc.first][cc.second] = 0;
            }
            return 1;
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (check2(nx, ny)) {
                if (!vis[nx][ny]) {
                    tmp.push_back(pii(nx, ny));
                    q.push(pii(nx, ny)), vis[nx][ny] = 1, pre[nx][ny] = pii(now.first, now.second);
                }
            } 
        }
    }
    return 0;
}
int main() {
    int t; in >> t;
    while (t--) {
        in >> n >> m;
        for (int i = 1; i <= n; i++) in >> s[i] + 1;
        queue<pii> b, g;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                can[i][j] = 0;
                vis[i][j] = 0;
                if (s[i][j] == 'B') {
                    for (int dir = 0; dir < 4; dir++) {
                        int x = i + dx[dir], y = j + dy[dir];
                        if (check1(x, y)) {
                            s[x][y] = '#';
                        }
                    }
                }
            }
        }
        can[n][m] = 1;
        bool fg = true, fb = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == 'G') fg &= work(i, j);
                if (s[i][j] == 'B') fb |= work(i, j);
            }
        }
        if (fg && !fb) puts("Yes");
        else puts("No");
    }
    return 0;
}
