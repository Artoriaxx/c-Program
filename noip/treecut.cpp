#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 10050
using namespace std;
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

struct node{
	int v,next;
}edge[maxn * 2];

int head[maxn],num;

inline void addedge(int u,int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int f[maxn];
int use[maxn],n;
void dfs1(int u,int fa){
	f[u] = 1;
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		dfs1(v, u);
		f[u] += f[v];
	}
}
int ans[maxn],cnt;
void dfs(int u,int fa){
	bool isok = 1;
	for(int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if(v == fa) continue;
		if(f[v] > n / 2) isok = 0;
		if(n - f[v] > n / 2) continue;
		dfs(v, u);
	}
	if(isok) ans[++cnt] = u;
}
int main(){
	n = getnum();
	for(int i = 1; i < n; i++){
		int a = getnum();
		int b = getnum();
		addedge(a, b);
		addedge(b, a);
	}
	dfs1(1,0);
	dfs(1,0);
	if(cnt == 0){
		printf("NONE\n");
		return 0;
	}
	sort(ans + 1, ans + cnt + 1);
	for(int i = 1; i <= cnt; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
