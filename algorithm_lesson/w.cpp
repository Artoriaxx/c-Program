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

const int N = 50;
char s[N][N];
struct node {
    int x, y;
    node (int x = 0, int y = 0): x(x), y(y) {}
};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool vis[N][N];
int n, m;
bool check(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n && !vis[x][y] && s[x][y] != '#';
}
int main() {
    
    while (scanf("%d%d", &n, &m) && n && m) {
        node st;
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= m; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == '@') {
                    st = node(i, j);
                }
            }
        }
        queue<node> q;
        q.push(st);
        int cnt = 1;
        vis[st.x][st.y] = 1;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (check(nx, ny)) {
                    vis[nx][ny] = 1;
                    cnt++;
                    q.push(node(nx, ny));
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    
    return 0;
}
