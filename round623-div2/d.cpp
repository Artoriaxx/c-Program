#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
struct node {
    ll a, t;
    bool operator < (const node &b) const {//重载优先队列小于号时，大小关系要反过来
        return t == b.t ? a > b.a : t < b.t;//按花费从大到小，标号从小到大顺序
    }
} a[N];
priority_queue<node> q;
map<ll, ll> f;
int find(int x) {
    return f[x] == 0 ? x : f[x] = find(f[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].a);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].t), q.push(a[i]);
    ll ans = 0;
    while (!q.empty()) {
        node now = q.top(); q.pop();
        int fa = find(now.a);
        ans += (fa - now.a) * now.t;
        f[fa] = fa + 1;
    }
    printf("%lld\n", ans);
    return 0;
}