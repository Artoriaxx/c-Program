#include<cstdio>
#include<queue>
#include<cstring>
#define pi pair<int,int>
#define maxm 500050
#define maxn 10050
using namespace std;

int n, m, s;

struct node{
	int v, next, w;
}edge[maxm * 2];

int num,head[maxn];

inline void addedge(int u, int v,int w){
	edge[++num].next = head[u];
	edge[num].v = v;
	edge[num].w = w;
	head[u] = num;
}

int d[maxn],vis[maxn];

void dijkstra(int s){
	priority_queue<pi, vector<pi>, greater<pi> > q;
	fill(d + 1, d + 1 + n, 2147483647);
	d[s] = 0;
	fill(vis + 1, vis + n + 1, false);
	q.push(make_pair(d[s], s));
	while(!q.empty()){
		pi now = q.top();
		q.pop();
		int x = now.second;
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = head[x]; i; i = edge[i].next){
			int v = edge[i].v;
			if(d[v] > d[x] + edge[i].w){
				d[v] = d[x] + edge[i].w;
				q.push(make_pair(d[v], v));
			}
		}
	}
}
int check[maxn];
void spfa(int s){
	queue <int> q;
	fill(vis + 1, vis + n + 1, false);
	fill(d + 1, d + n + 1, 2147483647);
	d[s] = 0;
	fill(check + 1, check + n + 1, 0);
	q.push(s); vis[s] = true; check[s] = 1;
	int isok = 1;
	while(!q.empty()){
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int i = head[x]; i; i = edge[i].next){
			int v = edge[i].v;
			if(d[v] > d[x] + edge[i].w){
				d[v] = d[x] + edge[i].w;
				if(!vis[v]){
					q.push(v);
					vis[v] = true;
					check[v]++;
					if(check[v] > n) isok = 0;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &s);
	int a, b, c;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
	}
//	dijkstra(s);
	spfa(s);
	for(int i = 1; i <= n; i++){
		printf("%d ", d[i]);
	}
	return 0;
}
