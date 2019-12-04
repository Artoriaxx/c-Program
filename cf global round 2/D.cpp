#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
ll a[N];
ll minu[N];
ll pre[100010];
int main() {
    int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
    } 
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	for(int i = 1; i < n; i++) {
        minu[i] = a[i + 1] - a[i];
    }
	sort(minu + 1, minu + n);
	for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + minu[i];
    }
    ll q;
	scanf("%lld", &q);
	for(int i = 1; i <= q; i++) {
		ll ans = 0;
        ll l, r;
		scanf("%lld%lld", &l, &r);
		ll len = r - l;
		ll pos = upper_bound(minu + 1,minu + n, len) - minu - 1;
		ans = pre[pos] + (n - pos) * (len + 1);
		printf("%lld ",ans);
	}
	return 0;
}