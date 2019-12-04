#include<bits/stdc++.h>
#define maxn 100050
#define re register int
using namespace std;
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int v, next;
}edge[maxn * 2];
int head[maxn], num;
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int point[maxn], dep[maxn];
void dfs1(int u, int fa){
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
	}
}
int vis[maxn];
void dfs2(int u, int fa, int step){
	vis[u] = 1;
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == fa) continue;
		if (step > 0) dfs2(v, u, step - 1);
	}
}
int cmp(int x, int y){
	return dep[x] > dep[y];
}
int main(){
	int n = getnum(), k = getnum(), t = getnum();
	for (re i = 1; i < n; i++){
		int a = getnum(), b = getnum();
		adde(a, b); adde(b, a);
	}
	for (re i = 1; i <= n; i++){
		point[i] = i;
	}
	dep[1] = 1;
	dfs1(1, 0);
	sort(point + 1, point + n + 1, cmp);
	int ans = 0;
	for (re i = 1; i <= n; i++){
		if (!vis[point[i]]){
			dfs2(point[i], 0, 2 * k);
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
} 
