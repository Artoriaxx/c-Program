#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
vector<int> G[N];
int dep[N];
int son[N];
int sze[N];
void dfs1(int u, int f) {
    sze[u] = 1;
    dep[u] = dep[f] + 1;
    son[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == f) continue;
        dfs1(v, u);
        sze[u] += sze[v];
        if (sze[v] > sze[son[u]]) son[u] = v;
    }
}
int c[N];
int maxv;
int now;
int ans[N];
int Son;
void calc(int u, int f, int val) {
    c[dep[u]] += val;
    if (c[dep[u]] > maxv) {
        now = dep[u];
        maxv = c[dep[u]];
    }
    else if (c[dep[u]] == maxv) {
        if (dep[u] < now) now = dep[u];
    }
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == f || v == Son) continue;
        calc(v, u, val);
    }
}
void dfs2(int u, int f, int op) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == f || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u]) {
        dfs2(son[u], u, 1);
        Son = son[u];
    }
    calc(u, f, 1);
    Son = 0;
    ans[u] = now - dep[u];
    if (!op) {
        calc(u, f, -1);
        now = 0;
        maxv = 0;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[0] = 0;
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}