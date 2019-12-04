#include<bits/stdc++.h>
#define maxn 200050
#define inf 0x3f3f3f3f
using namespace std;
//vector <int> G[maxn], val[maxn];
struct node{
	int v, next, w;
}edge[maxn * 2];
int head[maxn], num;
inline void adde(int u, int v, int w){
	edge[++num] = node{v, head[u], w};
	head[u] = num;
}
int n, m;
bool flag;
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int vis[maxn], d[maxn];
void spfa(int u){
	vis[u] = 1;
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (d[v] > d[u] + edge[i].w){
			d[v] = d[u] + edge[i].w;
			if (vis[v]){
				flag = true;
				return;
			}
			spfa(v);
		}
	}
	vis[u] = 0;
}
int main(){
	int t;
	t = getnum();
	while (t--){
		n = getnum(), m = getnum();
		memset(edge, 0, sizeof(edge));
		num = 0;
		memset(head, 0, sizeof(head));
		fill(vis + 1, vis + n + 1, 0);
		fill(d + 1, d + n + 1, 0);
		flag = false;
		for (int i = 1; i <= m; i++){
			int a = getnum(), b = getnum(), w = getnum();
			adde(a, b, w);
			if (w >= 0){
				adde(b, a, w);
			}
		}
		for (int i = 1; i <= n; i++){
			spfa(i);
			if (flag) break;
		}
		if (flag) printf("YE5\n");
		else printf("N0\n");
	}
} 
