#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100005;
inline ll getnum(){
	ll ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
//ll cnt[maxn], sum[maxn], ans[maxn];
inline ll cal(ll x, ll y, ll z, ll k){
	return k * (x + y) + (k * (k + 1)) / 2 * z; 
}
ll ans, ans1, ans2;
ll n, t, xi, yi, zi, li;

int main(){
	n = getnum(); t = getnum();
	for (int i = 1; i <= n; i++){
		xi = getnum(); yi = getnum(); zi = getnum();
		ll l = 0, r = t;
		if(zi) r = sqrt(2 * t / zi) + 10000;
		yi -= zi;
		while(l <= r){
			ll mid = (l + r) / 2;
			if(cal(xi, yi, zi, mid) <= t) ans = mid, l = mid + 1;
			else r = mid - 1; 
		}
		ans1 = ans * xi + min(t - cal(xi, yi, zi, ans), xi);
		ans2 += t - ans1;
	}
    cout<<ans2;
	return 0;
}
