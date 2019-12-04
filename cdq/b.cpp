#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
struct node {
    int a, b, c;
} p[N];
int pos[N];
int d[N];
void update(int x) {
    for (int i = x; i <= N - 10; i += i & (-i)) d[i] += 1;
}
ll query(int x) {
    ll ans = 0;
    for (int i = x; i; i -= i & (-i)) ans += d[i];
    return ans; 
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].a);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].b);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].c);
    ll ans = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
        pos[p[i].a] = i;
    }
    for (int i = 1; i <= n; i++) {
        update(pos[p[i].b]);
        ans += i - query(pos[p[i].b]);
    }
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
        pos[p[i].a] = i;
    }
    for (int i = 1; i <= n; i++) {
        update(pos[p[i].c]);
        ans += i - query(pos[p[i].c]);
    }
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
        pos[p[i].b] = i;
    }
    for (int i = 1; i <= n; i++) {
        update(pos[p[i].c]);
        ans += i - query(pos[p[i].c]);
    }
    printf("%lld\n", (ll)(1ll * n * (n - 1) - ans) >> 1);
    return 0;
}