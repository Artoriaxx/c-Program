#include<bits/stdc++.h>
#define maxn 100050 
using namespace std;
struct node{
	int v, next;
}edge[maxn * 2];
int head[maxn], num;
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int vis[maxn];int color[maxn];int ans1, ans2, flag;
void dfs(int u, int c){
	if (flag) return;
	if (color[u]){
		if (color[u] != c){
			flag = 1;
		}
		return;
	}
	color[u] = c;
	if (c == 1) ans1++;
	else ans2++;
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		dfs(v, c == 1 ? 2 : 1);
	}
}
int main(){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d", &a), scanf("%d", &b);
		adde(a, b), adde(b, a);
	}
	int ans = 0;
	flag = 0;
	for (int i = 1; i <= n; i++){
		if (!color[i]){
			ans1 = ans2 = 0;
			dfs(i, 1);
			if (flag){
				cout<<"Impossible";
				return 0;
			}
			ans += min(ans1, ans2);
		}
	}
	cout<<ans;
	return 0;
}
