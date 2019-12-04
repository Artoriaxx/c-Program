#include<iostream>
#include<cstdio>
#define maxn 300050
using namespace std;
int getnum(){
	int ans = 0; bool flag = false; char c;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int v,next;
}edge[maxn * 2];
int num,head[maxn * 2];
void adde(int u,int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
	edge[++num].next = head[v];
	edge[num].v = u;
	head[v] = num;
}
int n;
int a[maxn];
long long f[maxn],g[maxn];
void dfs(int u,int fa){
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v != fa){
			dfs(v, u);
			g[u] = max(g[u], g[v]);
			f[u] = max(f[u], f[v]);
		}
		long long t = f[u] - g[u] + a[u];
		if(t > 0) g[u] += t;
		else f[u] -= t;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = getnum();
	for(int i = 1; i <= n; i++){
		a[i] = getnum();
	}
	int p, q;
	for(int i = 1; i <= n - 1; i++){
		p = getnum(); q = getnum();
		adde(p, q);
	}
	dfs(1,0);
	printf("%lld", f[1] + g[1]);
	return 0;
}
