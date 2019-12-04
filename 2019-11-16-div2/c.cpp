#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
typedef long long ll;
ll a[N];
ll f[N];
ll pre[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0;
    ll d = 1;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = pre[i] - pre[max(0, i - m)];
        if (i >= m + 1) {
            f[i] += f[i - m] + pre[i - m];
        }
        printf("%lld ", f[i]);
    }
    return 0;
}