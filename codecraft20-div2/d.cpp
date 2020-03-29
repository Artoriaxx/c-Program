#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 50;
struct node {
    int x, y;
    bool operator == (const node &b) const {
        return x == b.x && y == b.y;
    }
} a[N][N];
char ans[N][N];
int vis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'L', 'U', 'R', 'D'};
char dir1[4] = {'R', 'D', 'L', 'U'};
int n;
bool isok(int x, int y, int i, int j) {
    return x >= 1 && x <= n && y >= 1 && y <= n && a[i][j] == a[x][y];
}
void dfs(int x, int y, int ix, int iy) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (vis[tx][ty]) continue;
        if (isok(tx, ty, ix, iy)) {
            ans[tx][ty] = dir[i];
            vis[tx][ty] = 1;
            dfs(tx, ty, ix, iy);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d%d", &a[i][j].x, &a[i][j].y);
            if (i == a[i][j].x && j == a[i][j].y) {
                ans[i][j] = 'X';
                vis[i][j] = 1;
            }
            
        }
    }
    int f = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 'X') {
                dfs(i, j, i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j].x == -1 && a[i][j].y == -1) {
                for (int k = 0; k < 4; k++) {
                    if (isok(i + dx[k], j + dy[k], i, j)) {
                        ans[i][j] = dir1[k];
                        vis[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == 0) {
                f = 0;
                break;
            }
        }
    }
    if (!f) {
        puts("INVALID");
    }
    else {
        puts("VALID");
        for (int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
    }
    return 0;
}