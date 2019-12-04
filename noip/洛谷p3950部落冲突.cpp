#include<bits/stdc++.h>
#define maxn 300050
#define re register int
using namespace std;
int in[maxn * 2], out[maxn * 2];
int n ,m;
inline int getnum(){
	char c; int ans = 0; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int v, next;
}edge[maxn * 2];
int head[maxn], num = 0;
inline int adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int f[maxn][22], dep[maxn];
void dfs1(int u, int fa){
	for (re i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == fa) continue;
		f[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
	}
}
int cnt = 0;
void dfs2(int u, int fa){
	in[u] = ++cnt;
	for (re i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v == fa) continue;
		dfs2(v, u);
	}
	out[u] = ++cnt;
}
int dis[maxn * 2];
inline void update(int x, int v){
	for (re i = x; i <= n << 1; i += i & (-i)){//记得要开两倍 
		dis[i] += v;
	}
}
inline int query(int x){
	int ans = 0;
	for (re i = x; i; i -= i & (-i)){
		ans += dis[i];
	}
	return ans;
}
inline void init(){
	for (re j = 1; j <= 20; j++){
		for (re i = 1; i <= n; i++){
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
}
inline int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (re i = 20; i >= 0; i--){
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--){
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}
int vis[maxn];
int main(){
	n = getnum(), m = getnum();
	for (re i = 1; i < n; i++){
		int a = getnum(), b = getnum();
		adde(a, b); adde(b, a);
	}
	dep[1] = 1;
	dfs1(1, 0);
	dfs2(1, 0);
	init();
	for (int i = 1; i <= n; i++){//在dfs序上差分 
		update(in[i], 1);
		update(out[i], -1);
	}
	int cnt1 = 0;
	while (m--){
		char s[5];
		scanf("%s", s);
		if (s[0] == 'Q'){
			int a = getnum(), b = getnum();
			int Lca = lca(a, b);
			int x = dep[a] + dep[b] - 2 * dep[Lca];//没有任何断点的长度 
			int y = query(in[a]) + query(in[b]) - 2 * query(in[Lca]);//如果有断点，那么距离肯定肯定不相等 
			if (x == y){
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
		if (s[0] == 'C'){
			int a = getnum(), b = getnum();
			if (dep[a] < dep[b]) a = b;
			vis[++cnt1] = a;
			update(in[a], -1);//发生战争 
			update(out[a], 1);
		}
		if (s[0] == 'U'){
			int a = getnum();
			int ai = vis[a];
			update(in[ai], 1);//战争停止，题目中保证了停止的一定是合法的 
			update(out[ai], -1);
		}
	}
	return 0;
}
