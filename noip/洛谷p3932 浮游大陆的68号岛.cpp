#include<bits/stdc++.h>
#define ll long long
#define p 19260817
#define maxn 200050
using namespace std;
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
ll ans, a[maxn], dis[maxn], b[maxn], pre[maxn], last[maxn], sum[maxn];
int main(){
	int n, m; n = getnum(); m = getnum();
	for (int i = 2; i <= n; i++){
		a[i] = getnum();
		dis[i] = (dis[i - 1] + a[i]) % p;
	}
	for (int i = 1; i <= n; i++){
		b[i] = getnum();
	}
	for (int i = 1; i <= n; i++){
		pre[i] = (pre[i - 1] + dis[i] * b[i] % p) % p;
	}
	for (int i = n - 1; i >= 1; i--){
		last[i] = (last[i + 1] + ((dis[n] - dis[i]) * b[i]) % p) % p;
	}
	for (int i = 1; i <= n; i++){
		sum[i] = (sum[i - 1] + b[i] % p) % p;
	}
	while (m--){
		int x = getnum(); int l = getnum(); int r = getnum();
		if (x <= l) ans = (((pre[r] - pre[l - 1] + p) % p - ((dis[x] * ((sum[r] - sum[l - 1] + p) % p) + p) % p)) + p) % p;
		else if (x >= r) ans = ((last[l] - last[r + 1] + p) % p - (((dis[n] - dis[x] + p) % p) * ((sum[r] - sum[l - 1] + p) % p) % p) + p) % p;
		else ans = (((last[l] - last[x + 1] + p) % p - (((dis[n] - dis[x] + p) % p) * ((sum[x] - sum[l - 1] + p) % p)) % p) + p) % p 
		+ (((pre[r] - pre[x - 1] + p) % p - (dis[x] * (((sum[r] - sum[x - 1]) + p) % p)) % p) + p) % p;
		printf("%lld\n", (ans + p) % p);
	}
	return 0;
} 
