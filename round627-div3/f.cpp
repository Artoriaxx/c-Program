#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
vector<int> G[N];
int a[N];
int ans[N];
int point;
int maxx;
int res[N];
void dfs(int u, int f) {
    ans[u] = a[u];
    for (auto v : G[u]) {
        if (v == f) continue;
        dfs(v, u);
        if (ans[v] > 0) ans[u] += ans[v];
    }
    if (ans[u] > maxx) maxx = ans[u], point = u;
    
}

void dfs2(int u, int f) {
    for (auto v : G[u]) {
        if (v == f) continue;
        if (ans[v] >= 0) res[v] = max(ans[v], res[u]);
        else res[v] = max(res[u] - 1, -1);
        dfs2(v, u);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!a[i]) a[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    maxx = -10086;
    dfs(1, 0);
    memset(ans, 0, sizeof(ans));
    dfs(point, 0);
    res[point] = ans[point];
    dfs2(point, 0);
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}