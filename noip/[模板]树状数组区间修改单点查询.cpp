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
	inline int query(int x){
		ll ans = 0;
		for (int i = x; i; i -= i & (-i)){
			ans += d[i];
		}
		return ans;
	}
} bit;
inline int getnum(){
	char c; bool flag = false; int ans = 0;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	n = getnum(), m = getnum();
	for (int i = 1; i <= n; i++){
		a[i] = getnum();
	}
	for (int i = 1; i <= m; i++){
		int t = getnum();
		if (t == 1){
			int l = getnum(), r = getnum(), v = getnum();
			bit.update(l, v), bit.update(r + 1, -v);
		}
		if (t == 2){
			int x = getnum();
			printf("%d\n", a[x] + bit.query(x));
		}
	}
	return 0;
} 
