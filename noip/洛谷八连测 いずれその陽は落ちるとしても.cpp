#include<bits/stdc++.h>
#define ll long long
#define re register int
#define maxn 1000050
using namespace std;
ll d[maxn];
int n;
inline void update(int x, int v){
	for (re i = x; i <= n; i += i & (-i)){
		d[i] += v;
	}
}
inline ll query(int x){
	ll ans = 0;
	for (re i = x; i; i -= i & (-i)){
		ans += d[i];
	}
	return ans;
}
int a[maxn];
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int b[maxn];
int main(){
	n = getnum();
	for (re i = 1; i <= n; i++){
		b[i] = a[i] = getnum();
	}
	sort(a + 1, a + n + 1);
	for (re i = 1; i <= n; i++){
		b[i] = lower_bound(a + 1, a + n + 1, b[i]) - a;
	}
	ll ans = 0;
	for (re i = 1; i <= n; i++){
		ans += (((ll)i * (i - 1) >> 1) - query(b[i])) * (n - i + 1);
		update(b[i], i);
	}
	printf("%lld", ans);
	return 0;
}
