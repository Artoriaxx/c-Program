#include<bits/stdc++.h>
using namespace std;
const int maxn = 300050;
int n, m;
struct node{
	int v, next;
}edge[maxn * 2];
struct point{
	int s, t;
}run[maxn];
vector<int> q1[maxn], q2[maxn], q3[maxn];
int mark[maxn], t[maxn * 2], ans[maxn];
int num, head[maxn];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int w[maxn];
int fa[maxn][25];
inline void init(){
	for (int j = 1; j <= 23; j++){
		for (int i = 1; i <= n; i++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}
int dep[maxn];
void build(int u, int f){
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == f) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		build(v, u);
	}
}
inline int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 23; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 23; i >= 0; i--){
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
int maxdep;
void dfs1(int u, int f){
	int v, now = dep[u] + w[u], pre = 0;//我们发现在s -> t路径上能够被观测到的点满足dep[x] + w[x] = dep[s]; 
	if (now <= maxdep) pre = t[now];//所以我们就统计有多少个这样的点，用一个桶下标存储左式，值存储右式。 
	for (int i = head[u]; i; i = edge[i].next){
		v = edge[i].v;
		if (v == f) continue;
		dfs1(v, u);
	}//要从子树开始查询 
	t[dep[u]] += mark[u];
	if (now <= maxdep) ans[u] += t[now] - pre;//由于在dfs的过程中t的值已经改变，所以观测到的点就是变化量 
	for (int i = 0; i < q1[u].size(); i++){
		t[q1[u][i]]--;//遍历到lca时，把这个影响消除，减去所有到lca的起点的影响 
	}
}
void dfs2(int u, int f){
	int now = dep[u] - w[u] + maxn, pre = 0;//在lca -> t路径上，需要满足dep[u] - w[u] = dep[lca] - len 
	pre = t[now];//由于可能出现负数，把桶下标向右移动3e5 
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == f) continue;
		dfs2(v, u);
	}
	for (int i = 0; i < q2[u].size(); i++){//q2，q3用于差分 
		t[q2[u][i] + maxn]++;
	}
	ans[u] += t[now] - pre;//同上 
	for (int i = 0; i < q3[u].size(); i++){
		t[q3[u][i] + maxn]--;
	}
}
int main(){
	n = getnum(), m = getnum();
	for (int i = 1; i < n; i++){
		int a = getnum(), b = getnum();
		adde(a, b), adde(b, a);
	}
	for (int i = 1; i <= n; i++){
		w[i] = getnum();
	}
	dep[1] = 1;
	build(1, 0);
	init();
	for (int i = 1; i <= n; i++) maxdep = max(maxdep, dep[i]);
	for (int i = 1; i <= m; i++){
		run[i].s = getnum(), run[i].t = getnum();
	}
	for (int i = 1; i <= m; i++){
		mark[run[i].s]++;//先处理s -> lca,mark[i]表示第i个节点作为起点多少次  
		int Lca = lca(run[i].s, run[i].t);
		q1[Lca].push_back(dep[run[i].s]);//q1[i]存储lca为i的人的起点的深度 
	}
	dfs1(1, 0);
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= m; i++){
		int Lca = lca(run[i].s, run[i].t);
		int dis = dep[run[i].s] + dep[run[i].t] - 2 * dep[Lca];
		int tmp = dep[run[i].t] - dis;
		q2[run[i].t].push_back(tmp);
		q3[Lca].push_back(tmp);
	}
	dfs2(1, 0);
	for (int i = 1; i <= m; i++){
		int Lca = lca(run[i].s, run[i].t);
		if (dep[run[i].s] - dep[Lca] == w[Lca]) --ans[Lca];
	}
	for (int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
