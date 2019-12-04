#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
struct edge{
	int v,next,w;
}edge[maxn * 2];
int num = 0; int head[maxn];
inline void addedge(int u,int v,int w){
	edge[++num].next = head[u];
	edge[num].v = v;
	edge[num].w = w;
	head[u] = num;
}
int a[maxn],dis1[maxn];
void dfs1(int now,int fa){
	for(int i = head[now]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		dis1[v] = dis1[now] + edge[i].w;
		dfs1(v, now);
	}
}
int dis2[maxn];
void dfs2(int now,int fa){
	for(int i = head[now]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		dis2[v] = dis2[now] + edge[i].w;
		dfs2(v, now);
	}
}
int ans1, ans2,vis[maxn];
void dfs(int now,int fa){
	for(int i = head[now]; i; i = edge[i].next){
		int v = edge[i].v;
		if(!vis[now]){
			if(dis1[now] > dis2[now]) ans1 += a[now];
			else if(dis1[now] < dis2[now]) ans2 += a[now];
		}
		vis[now] = 1;
		if(v == fa) continue;
		dfs(v, now);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int t;
	scanf("%d", &t);
	int x,y;
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &x, &y);
		ans1 = 0;
		ans2 = 0;
		memset(dis1, 0, sizeof(dis1));
		memset(dis2, 0, sizeof(dis2));
		memset(vis, 0, sizeof(vis));
		dfs1(x, -1);
		dfs2(y, -1);
		dfs(1, -1);
		printf("%d %d\n",ans2, ans1);
	}
	return 0;
}
