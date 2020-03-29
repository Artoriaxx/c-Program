#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
typedef long long ll;
const int N = 1e6 + 50;
ll a[N], b[N];
int main() {
    int n, m; ll p;
    scanf("%d%d%lld", &n, &m, &p);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), a[i] %= p;
    for (int i = 0; i < m; i++) scanf("%lld", &b[i]), b[i] %= p;
    int ans;
    for (int i = 0; i < n; i++) if (a[i]) {
        ans = i;
        break;
    }
    for (int i = 0; i < m; i++) if (b[i]) {
        ans += i;
        break;
    }
    printf("%d\n", ans);
    
    return 0;
}
