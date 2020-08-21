#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 50;
vector<int> G[N];
int cnt;
struct node {
    int x, y, id;
    node(int x = 0, int y = 0, int id = 0): x(x), y(y), id(id) {}
} ans[N];
void dfs(int u, int f) {
    for (auto v : G[u]) {
        if (v == f) continue;
        if (G[v].size() == 1) ans[v] = ans[u];
        else {
            if (ans[u].id == 0) {
                ans[v].x = ans[u].x;
                ans[v].y = ++cnt;
                ans[u].id ^= 1;
                ans[v].id = 1;
            }
            else {
                ans[v].x = ans[u].y;
                ans[v].y = ++cnt;
                ans[u].id ^= 1;
                ans[v].id = 1;
            }
        }
        dfs(v, u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans[1] = node(1, 2, 0);
    cnt = 2;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}
