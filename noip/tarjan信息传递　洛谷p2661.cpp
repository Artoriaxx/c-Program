#include<iostream>
#include<cstring>
#include<vector>
#define maxm 200005
#define maxn 200005
using namespace std;
int tmp, cnt;//tmp记录时间戳，cnt记录有几个强联通分量
struct node{
	int v, next;
}edge[maxm];
int num, head[maxn];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
vector<int> umi[maxn];
int ans, ans1 = 0x3f3f3f3f;
int dfn[maxn], low[maxn], vis[maxn], stack[maxn], p, belong[maxn];
void tarjan(int u){
	int v;
	dfn[u] = ++tmp;//记录时间戳 
	low[u] = tmp;
	vis[u] = true;//是否在栈中 
	stack[++p] = u;
	for (int i = head[u]; i; i = edge[i].next){
		v = edge[i].v;
		if (!dfn[v]){//如果dfn没有被更新过，则递归下一个点 
			tarjan(v);
			low[u] = min(low[u], low[v]);//如果和它相连的点指向能回溯的点更小，则更新该点的low 
		}
		else if (vis[v] && dfn[v] < low[u]) low[u] = dfn[v];//
	}
	if (dfn[u] == low[u]){
		cnt++;
		ans = 0;
		do {
			v = stack[p--];
			vis[v] = false;
//			belong[v] = cnt;
//			umi[cnt].push_back(v);
			ans++;
		} while (v != u);
		if(ans > 1){
			ans1 = min(ans1, ans);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int o;
	for (int i = 1; i <= n; i++){
		cin >> o;
		adde(i, o);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	cout<<ans1;
	return 0;
}
