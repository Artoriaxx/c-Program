#include<iostream>
#include<cstdio>
#define maxn 500050
#define getnum ip.read
using namespace std;
struct io{
	char op[1 << 26], *s;
	io(){
		freopen("t.txt", "r", stdin);
		fread(s = op , 1 , 1 << 26 , stdin);
	}
	inline int read(){
		register int u = 0;
		while( *s < 48 ) s++;
		while( *s > 32 )
			u = u * 10 + *s++ - 48;
		return u;
	}
} ip;
struct node{
	int v, next;
}edge[maxn * 2];
int num, head[maxn];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int n, m, s;
int fa[maxn][20]; int dep[maxn];
void dfs(int u){
	for (register int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(!dep[v]){
			fa[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
}

inline void init(){
	for (register int i = 1; i <= 19; i++){
		for (register int j = 1; j <= n; j++){
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
}
inline int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (register int i = 19; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (register int i = 19; i >= 0; i--){
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i]; y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	n = getnum(), m = getnum(), s = getnum();
	for (register int i = 1; i < n; i++){
		int a, b;
		a = getnum(), b = getnum();
		adde(a, b), adde(b, a);
	}
	dep[s] = 1;
	dfs(s);
	init();
	for(register int i = 1; i <= m; i++){
		int a, b;
		a = getnum(), b = getnum();
		printf("%d\n", lca(a, b));
	}
	return 0;
}
