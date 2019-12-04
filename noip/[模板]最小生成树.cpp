#include<bits/stdc++.h>
#define maxm 200050
#define maxn 5050
#define ll long long
using namespace std;
int n, m;
struct node{
	int x, y, val;
}e[maxm];
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int cmp(node x, node y){
	return x.val < y.val;
}
int f[maxn];
inline void init(){
	for (int i = 1; i <= n; i++){
		f[i] = i;
	}
}
inline int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
	n = getnum(), m = getnum();
	for (int i = 1; i <= m; i++){
		e[i].x = getnum(), e[i].y = getnum(), e[i].val = getnum(); 
	}
	sort(e + 1, e + m + 1, cmp);
	ll ans = 0;
	init();
	for (int i = 1; i <= m; i++){
		int a = find(e[i].x), b = find(e[i].y);
		if (a != b){
			ans += e[i].val;
			f[a] = b;
		}
	}
	printf("%lld", ans);
	return 0;
}
