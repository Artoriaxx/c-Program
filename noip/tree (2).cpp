#include<iostream>
#define maxn 300050
using namespace std;
struct node{
	long long v,next;
}edge[maxn];
int num,head[maxn];
void adde(int u,int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int n;
int a[maxn];
long long f[maxn],g[maxn];
void dfs(int u,int fa){
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u);
		g[u] = max(g[u], g[v]);
		f[u] = max(f[u], f[v]);
		long long t = f[u] - g[u] + a[u];
		if(t > 0) g[u] += t;
		if(t < 0) f[u] += t;
	}
}
int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int p, q;
	for(int i = 1; i <= n - 1; i++){
		cin>>p>>q;
		adde(p, q);
		adde(q, p);
	}
	dfs(1,0);
	cout<<f[1] + g[1];
	return 0;
}
