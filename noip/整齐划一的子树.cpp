#include<cstdio>
using namespace std;
struct edge{
	int v; int next;
}edge[maxm];
inline void addedge(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n - 1; i++){
		cin>>a>>b;
		addedge(a, b);
		addedge(b, a);
	}
	
}
