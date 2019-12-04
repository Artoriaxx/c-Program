#include<cstdio> 
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 10050;
const int maxm = 200050;
int n, m, s, t;
int x[maxm], y[maxm];
struct node{
	int v, next;
}edge[maxm];
int num, head[maxm];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int vis[maxn];
void dfs(int u){
	vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(!vis[v]){
			vis[v] = 1;
			dfs(v);
		}
	}
}
bool check(int u){
	if(!vis[u]) return false;
	else{
		for(int i = head[u]; i; i = edge[i].next){
			int v = edge[i].v;
			if(!vis[v]) return false;
		}
		return true;
	}
	
}
int dis[maxn];
int bfs(){
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty()){
		int x = q.front();q.pop();
		if(!check(x)) continue;
		for(int i = head[x]; i; i = edge[i].next){
			int v = edge[i].v;
			if(!check(v)) continue;
			if(dis[v] == -1){
				dis[v] = dis[x] + 1;
				q.push(v);
				if(v == t){
					printf("%d", dis[v]);
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &x[i], &y[i]);
		adde(y[i], x[i]);
	}
	scanf("%d%d", &s, &t);
	dfs(t);
	memset(head, 0, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dis, -1, sizeof(dis));//有环的情况下不加这个就炸了 
	num = 0;
	for(int i = 1; i <= m; i++){
		adde(x[i], y[i]);
	}
	if(!vis[s]){
		printf("-1");
		return 0;
	} 
	if(!bfs()){
		printf("-1");
	}
	return 0;
}
