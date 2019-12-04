#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int n; ll k;
ll a[N];
ll pre[N];
bool check(ll x) {
    int l = 1, r = n;
    ll lsum, rsum;
    for (int i = 1; i <= n; i++) {
        lsum = rsum = 0;
        while (l < i && a[i] - a[l] > x) l++;
        lsum += max(0ll, (a[i] - x) * (ll)(l - 1) - pre[l - 1]);
        rsum += pre[n] - pre[i] - a[i] * (ll)(n - i);
        if (lsum + rsum <= k) return true;
    }
    for (int i = n; i >= 1; i--) {
        lsum = rsum = 0;
        while (r > i && a[r] - a[i] > x) r--;
        lsum += a[i] * (ll)(i - 1) - pre[i - 1];
        rsum += max(0ll, pre[n] - pre[r] - (a[i] + x) * (ll)(n - r));
        if (lsum + rsum <= k) return true;
    }
    return false;
}
int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    check(1);
    int l = 0, r = 1e9;
    int ans = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}