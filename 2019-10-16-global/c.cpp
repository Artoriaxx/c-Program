#include <bits/stdc++.h>
using namespace std;
const int N = 50050;
typedef long long ll;
struct node {
    ll x, y, z, id;
} p[N];
ll x = -1e9, y = -1e9, z = -1e9;
bool cmp(node a, node b) {
    return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y) + (a.z - z) * (a.z - z) <= (b.x - x) * (b.x - x) + (b.y - y) * (b.y - y) + (b.z - z) * (b.z - z);
}
int vis[N];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z);
        p[i].id = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (vis[p[i].id]) continue;
        vis[p[i].id] = 1;
        printf("%d ", p[i].id);
        ll diss = 1e18;
        int pp;
        for (int j = 1; j <= n; j++) {
            if (vis[p[j].id]) continue;
            if ((p[j].x - p[i].x) * (p[j].x - p[i].x) + (p[j].y - p[i].y) * (p[j].y - p[i].y) + (p[j].z - p[i].z) * (p[j].z - p[i].z) <= diss) {
                diss = (p[j].x - p[i].x) * (p[j].x - p[i].x) + (p[j].y - p[i].y) * (p[j].y - p[i].y) + (p[j].z - p[i].z) * (p[j].z - p[i].z);
                pp = j;
            }
            if (p[j].x >= p[pp].x && p[j].y >= p[pp].y && p[j].z >= p[pp].z) break;
        }
        vis[p[pp].id] = 1;
        printf("%d\n", p[pp].id);
    }
    return 0;
}