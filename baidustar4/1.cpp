#include <bits/stdc++.h>
using namespace std;
const int N = 350;
struct Edge {
    int u, v, id;
} edge[N];
int f[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int num[N][N];
bool cmp(Edge a, Edge b) {
    return num[a.u][a.v] > num[b.u][b.v];
}
int vis[N];

int in[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &edge[i].u, &edge[i].v);
            if (edge[i].u > edge[i].v) swap(edge[i].u, edge[i].v);
            edge[i].id = i;
            in[edge[i].u]++;
            in[edge[i].v]++;
        }
        //sort(edge + 1, edge + m + 1, cmp);
        memset(vis, 0, sizeof(vis));
        bool flag = true;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (in[i] < k) {
                flag = false;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
