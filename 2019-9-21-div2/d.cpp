#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50;
typedef long long ll;
struct node {
    ll a, b, cnt;
} p[N];
bool cmp(node x, node y) {
    return x.a < y.a;
}
ll sum[N];
int vis[N];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].a);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].b);
    }
    sort(p + 1, p + n + 1, cmp);
    int cnt = 0;
    int t;
    for (int i = 1; i <= n; i = t) {
        t = i + 1;
        p[++cnt] = p[i];
        p[cnt].cnt = 1;
        while (t <= n && p[t].a == p[i].a) {
            p[cnt].b += p[t].b;
            p[cnt].cnt++;
            t++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (p[i].cnt >= 2) {
            ans += p[i].b;
            vis[i] = 1;
            for (int j = 1; j < i; j++) {
                if (vis[j]) continue;
                if ((p[j].a | p[i].a) == p[i].a) {
                    ans += p[j].b;
                    vis[j] = 1;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}