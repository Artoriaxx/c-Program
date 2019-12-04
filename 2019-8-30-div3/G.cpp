#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &b) const {
        return w < b.w;
    }
} edge[N];
struct node {
    int id, w;
    bool operator < (const node &b) const {
        return w < b.w;
    }
} q[N];
ll ans[N];
int fa[N], num[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    for (int i = 1; i <= m; i++) scanf("%d", &q[i].w), q[i].id = i;
    sort(q + 1, q + m + 1);
    sort(edge + 1, edge + n);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        num[i] = 1;
    }
    int now = 1;
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        while (edge[now].w <= q[i].w && now < n) {
            int x = find(edge[now].u);
            int y = find(edge[now].v);
            res += 1ll * num[x] * num[y];
            fa[x] = y;
            num[y] += num[x];
            now++;
        }
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}