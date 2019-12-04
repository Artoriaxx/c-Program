#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char s[N];
vector<vector<char> > mp;
bool vis[N];
bool flag;
int n, m;
void dfs(int x, int y) {
    if (x == n && y == m) {
        flag = 1;
    }
    if (flag) return;
    if (x + 1 <= n && vis[x * m + y] == 0 && mp[x][y - 1] != '#') {
        vis[x * m + y] = 1;
        mp[x][y - 1] = '#';
        dfs(x + 1, y);
        if (!flag) mp[x][y - 1] = '.';
    }
    if (flag) return;
    if (y + 1 <= m && vis[(x - 1) * m + y + 1] == 0 && mp[x - 1][y] != '#') {
        vis[(x - 1) * m + y + 1] = 1;
        mp[x - 1][y] = '#';
        dfs(x, y + 1);
        if (!flag) mp[x - 1][y] = '.';
    }
}
int main() {
    
    scanf("%d%d", &n, &m);
    mp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            mp[i].push_back(s[j]);
        }
    }
    flag = 0;
    dfs(1, 1);
    if (flag == 0) {
        puts("0");
        return 0;
    }
    flag = 0;
    mp[n - 1][m - 1] = '.';
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    if (flag == 0) {
        puts("1");
        return 0;
    }
    puts("2");
    return 0;
}