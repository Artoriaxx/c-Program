#include<bits/stdc++.h>
#define maxn 100060
#define p 99999997
using namespace std;
int c[maxn], d[maxn], n;
inline int getnum(){
	char c; int ans = 0; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	long long v; int pos;
}a[maxn], b[maxn];
int cmp(node x, node y){
	return x.v < y.v;
}
inline int lowbit(int x){
	return x & (-x);
}
inline void updata(int x){
	while (x <= n){
		d[x]++;
		x += lowbit(x);
	}
}
inline int getsum(int x){
	int ans = 0;
	while (x > 0){
		ans += d[x] % p;
		x -= lowbit(x);
	}
	return ans;
}
int main(){
	n = getnum();
	for (int i = 1; i <= n; i++){
		a[i].v = getnum();
		a[i].pos = i;
	}
	for (int i = 1; i <= n; i++){
		b[i].v = getnum();
		b[i].pos = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		c[b[i].pos] = a[i].pos;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		updata(c[i]);
		ans += i - getsum(c[i]);
		ans %= p;
	}
	printf("%d", ans);
	return 0;
}
