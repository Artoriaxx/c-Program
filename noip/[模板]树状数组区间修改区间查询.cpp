#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
#define maxn 500050
using namespace std;
int n, m;
int a[maxn];
struct BIT{
	ll d[maxn];
	inline void update(int x, int v){
		for (int i = x; i <= n; i += i & (-i)){
			d[i] += v;
		}
	}
	inline ll query(int x){
		ll ans = 0;
		for (int i = x; i; i -= i & (-i)){
			ans += d[i];
		}
		return ans;
	}
} bit1, bit2;
inline int getnum(){
	char c; bool flag = false; int ans = 0;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	n = getnum(), m = getnum();
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++){
		a = getnum();
		bit1.update(i, a - b);
		bit2.update(i, (ll)(i - 1) * (a - b));
		b = a;
	}
	for (int i = 1; i <= m; i++){
		int t = getnum();
		if (t == 1){
			ll l = getnum(), r = getnum(), v = getnum();
			bit1.update(l, v), bit1.update(r + 1, -v);
			bit2.update(l, v * (l - 1)), bit2.update(r + 1, - v * r);
		}
		if (t == 2){
			ll l = getnum(), r = getnum();
			ll sum1 = (l - 1) * bit1.query(l - 1) - bit2.query(l - 1);
			ll sum2 = r * bit1.query(r) - bit2.query(r);
			printf("%lld\n", sum2 - sum1);
		}
	}
	return 0;
}
