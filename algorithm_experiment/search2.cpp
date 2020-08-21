#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2050;
struct node {
    int x, y;
    node(int x = 0, int y = 0): x(x), y(y) {}
};
char s[N][N];
bool vis[N][N];
int n;
node st, ed;
bool check(int x, int y) {
    return x >= 0 & x < n && y >= 0 && y < n && s[x][y] != 'X' && !vis[x][y];
}
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
node pre[N][N];
int d[N][N];
void print(int x, int y) {
    if (x == st.x && y == st.y);
    else print(pre[x][y].x, pre[x][y].y);
    printf("(%d %d)->", x, y);
}
int main() {
    scanf("%d%d%d%d%d", &n, &ed.x, &ed.y, &st.x, &st.y);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    queue<node> q;
    vis[st.x][st.y] = 1;
    d[st.x][st.y] = 0;
    q.push(st);
    while (!q.empty()) {
        node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            node nx = node(now.x + dx[i], now.y + dy[i]);
            if (check(nx.x, nx.y)) {
                pre[nx.x][nx.y] = node(now.x, now.y);
                vis[nx.x][nx.y] = 1;
                d[nx.x][nx.y] = d[now.x][now.y] + 1;
                q.push(nx);
            }
        }
    }
    printf("%d\n", d[ed.x][ed.y]);
    node tmp = pre[ed.x][ed.y];
    print(tmp.x, tmp.y);
    printf("(%d %d)", ed.x, ed.y);
    return 0;
}
