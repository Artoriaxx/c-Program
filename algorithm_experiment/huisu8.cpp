#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 55;
//dir = 0 y在x下
//dir = 1 y在x右
int vis[N][N];
int n, m;
int up[12], down[12], l[12], r[12];
char mp[N][N];
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y];
}
bool judge(char x, char y, int dir) {
    if (dir == 0) return down[x - 'A'] == 1 && up[y - 'A'] == 1;
    else return r[x - 'A'] == 1 && l[y - 'A'] == 1;
}
void dfs(int x, int y) {
    vis[x][y] = 1;
    if (check(x, y + 1))
        if (judge(mp[x][y], mp[x][y + 1], 1))
            dfs(x, y + 1);
    if (check(x, y - 1))
        if (judge(mp[x][y - 1], mp[x][y], 1))
            dfs(x, y - 1);
    if (check(x + 1, y)) 
        if (judge(mp[x][y], mp[x + 1][y], 0))
            dfs(x + 1, y);
    if (check(x - 1, y))
        if (judge(mp[x - 1][y], mp[x][y], 0))
            dfs(x - 1, y);
    
}
int main() {
    up[0] = l[0] = 1;
    up[1] = r[1] = 1;
    l[2] = down[2] = 1;
    r[3] = down[3] = 1;
    up[4] = down[4] = 1;
    l[5] = r[5] = 1;
    up[6] = l[6] = r[6] = 1;
    up[7] = l[7] = down[7] = 1;
    down[8] = l[8] = r[8] = 1;
    r[9] = up[9] = down[9] = 1;
    up[10] = down[10] = l[10] = r[10] = 1;
    while (scanf("%d%d", &n, &m) && ~n && ~m) {
        for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
