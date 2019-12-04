#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 100050
#define re register int
using namespace std;
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int x, y;
}a[maxn], vis[maxn];
int cmp(node x, node y){
	if (x.x < y.x){
		return 1;
	} 
	else if (x.x == y.x){
		return x.y < y.y;
	}
	return 0;
}
int main(){
	int t;
	t = getnum();
	while (t--){
		int n = getnum(), m = getnum(), q = getnum();
		memset(vis, 0, sizeof(vis));
		for (re i = 1; i <= q; i++){
			a[i].x = getnum(), a[i].y = getnum();
		}
		sort(a + 1, a + q + 1, cmp);
		int ans = 0;
		for (re i = 1; i <= q; i++){
			if (!vis[a[i].x].x && !vis[a[i].y].y) vis[a[i].x].x = 1, vis[a[i].y].y = 1, ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
} 
