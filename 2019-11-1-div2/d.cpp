#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2050;
struct node {
    ll x, y, c, k, id, t, link;
    node (ll x = 0, ll y = 0): x(x), y(y) {}
} p[N];
ll cost[N][N];
bool cmp(node a, node b) {
    return a.t < b.t;
}
ll ans1[N * 100];
ll ans2x[N * 100], ans2y[N * 100];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y), p[i].id = i;
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i].c), p[i].t = p[i].c;
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i].k);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll x = p[i].k + p[j].k;
            cost[i][j] = cost[j][i] = x * (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y));
        }
    }
    //printf("--%lld %lld--\n", cost[1][2], cost[2][3]);
    ll ans = 0, cnt1 = 0, cnt2 = 0;
    sort(p + 1, p + n + 1, cmp);
    
    for (int i = 1; i <= n; i++) {
        if (cnt1 == 0) {
            cnt1++;
            ans += p[i].t;
            ans1[cnt1] = p[i].id;
            for (int j = i + 1; j <= n; j++) {
                if (cost[p[j].id][p[i].id] < p[j].t) {
                    p[j].t = cost[p[j].id][p[i].id];
                    p[j].link = p[i].id;
                }
            }
            continue;
        }
        sort(p + i, p + n + 1, cmp);
        if (p[i].link != 0) {
            cnt2++;
            ans += p[i].t;
            ans2x[cnt2] = p[i].id;
            ans2y[cnt2] = p[i].link;
        }
        else {
            cnt1++;
            ans += p[i].t;
            ans1[cnt1] = p[i].id;
        }
        for (int j = i + 1; j <= n; j++) {
            if (cost[p[j].id][p[i].id] < p[j].t) {
                p[j].t = cost[p[j].id][p[i].id];
                p[j].link = p[i].id;
            }
        }
    }
    printf("%lld\n", ans);
    printf("%lld\n", cnt1);
    for (int i = 1; i <= cnt1; i++) {
        printf("%lld ", ans1[i]);
    }
    puts("");
    printf("%lld\n", cnt2);
    for (int i = 1; i <= cnt2; i++) {
        printf("%lld %lld\n", ans2x[i], ans2y[i]);
    }
    return 0;
}