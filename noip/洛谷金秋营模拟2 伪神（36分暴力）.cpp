#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define maxn 400005
#define maxm 100005
using namespace std;

int n, m, cnt1[maxm], cnt2[maxm], fa[maxm][25], dep[maxm];

inline int read(){
	char c; int ans = 0; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

struct node{
	int v, next;
}edge[maxn * 2];

int num, head[maxm];

inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}

void dfs(int u, int fa1){
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa1) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		dfs(v, u);
	}
}

void dfs2(int u, int fa){
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		cnt2[v] += cnt2[u];
		dfs2(v, u);
		cnt1[u] += cnt1[v];  
		
	}
}

inline void init(){
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= n; j++){
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
}

inline int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--){
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int main(){
	n = read(); m = read();
	for (int i = 1; i <= n - 1; i++){
		int x, y;
		x = read(), y = read();
		adde(x, y); adde(y, x);
	}
	dep[1] = 1;
	dfs(1, 0);
	init();
	int a, b, t;
	for (int i = 1; i <= m; i++){
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		a = read(); b = read(); t = read();
		for(int j = 1; j <= a; j++){
			int x, y;
			x = read(); y = read();
			int q = lca(x, y);
			cnt1[x]++, cnt1[y]++, cnt1[q]--, cnt1[fa[q][0]]--;
		}
		for(int j = 1; j <= b; j++){
			int x;
			x = read();
			cnt2[x]++;
		}
		dfs2(1, 0);
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			if(cnt1[i] + cnt2[i] >= t) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
