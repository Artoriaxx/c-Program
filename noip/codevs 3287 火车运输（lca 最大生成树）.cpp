#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxm 50050
#define maxn 10050
using namespace std;

int fa[maxn]; int n, m;
int u[maxm], v[maxm], w[maxm];

inline int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct node{
	int v, next, w;
}edge[maxm * 2];

int num,head[maxn];

inline void addedge(int u,int v,int w){
	edge[++num].next = head[u];
	edge[num].v = v;
	edge[num].w = w;
	head[u] = num;
}

int cmp(int x, int y){
	return w[x] > w[y];
}

int r[maxm];

inline void kruskal(){
	for(int i = 1; i <= m; i++) r[i] = i;
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(r + 1, r + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		int x = u[r[i]];int y = v[r[i]];
		x = find(x); y = find(y);
		if(x != y){
			addedge(u[r[i]], v[r[i]], w[r[i]]);
			addedge(v[r[i]], u[r[i]], w[r[i]]);
			fa[x] = y;
		}
	}
}
int f[maxn][20];

int vis[maxn],dist[maxn][25],d[maxn];

void dfs(int u){
	vis[u] = 1;
	for(int i = 1; (1 << i) <= d[u]; i++){
		f[u][i] = f[f[u][i - 1]][i - 1];
		dist[u][i] = min(dist[u][i - 1], dist[f[u][i - 1]][i - 1]);
	}
	for(int i = head[u]; i;i = edge[i].next){
		int v = edge[i].v;
		if(!vis[v]){
			d[v] = d[u] + 1;
			dist[v][0] = edge[i].w;
			f[v][0] = u;
			dfs(v);
		}
	}
}

int lca(int x, int y){
	int inf = 0x3f3f3f3f;
	if(d[x] < d[y]) swap(x, y);
	int minus = d[x] - d[y];
	for(int i = 0; (1 << i) <= minus; i++){
		if(((1 << i) & minus) && f[x][i]){
			inf = min(inf, dist[x][i]);
			x = f[x][i];	
		}
	}
	if(x == y) return inf;
	for(int i = 20; i >= 0; i--){
		if(f[x][i] != f[y][i] && d[x] >= (1 << i) && f[x][i]){
			inf = min(inf, min(dist[x][i], dist[y][i]));
			x = f[x][i];
			y = f[y][i];
		}
	}
	return min(inf, min(dist[x][0], dist[y][0]));
}
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	n = getnum(); m = getnum();
	for(int i = 1; i <= m; i++){
		u[i] = getnum();
		v[i] = getnum();
		w[i] = getnum();
	}
	kruskal();
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}
	int q = getnum();
	for(int i = 1; i <= q; i++){
		int a = getnum();int b = getnum();
		if(find(a) != find(b)) printf("-1\n");
		else printf("%d\n", lca(a, b));
	}
	return 0;
} 
