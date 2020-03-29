#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
ll a[N];
int vis[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        vis[a[i] % m]++;
        if (vis[a[i] % m] > 1) flag = false;
    }
    if (!flag) {
        puts("0");
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = ans * abs(a[i] - a[j]) % m;
        }
    }
    printf("%lld\n", ans);

    return 0;
}