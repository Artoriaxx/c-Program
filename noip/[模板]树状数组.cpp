#include<bits/stdc++.h>
#define ll long long
#define maxn 500050
using namespace std;
int n, m;
struct BIT {
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
}bits;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		bits.update(i, a);
	}
	for (int i = 1; i <= m; i++){
		int t;
		scanf("%d", &t);
		if (t == 1){
			int x, v;
			scanf("%d%d", &x, &v);
			bits.update(x, v);
		}
		if (t == 2){
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%lld\n", bits.query(y) - bits.query(x - 1));
		}
	}
	return 0;
}
