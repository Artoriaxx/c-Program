#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
vector<int> G[N];
int ans[N];
int deg[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        deg[v]++;
        ans[i] = (u < v) + 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        puts("1");
        for (int i = 1; i <= m; i++) printf("1 ");
    }
    else {
        puts("2");
        for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
    }
    return 0;
}