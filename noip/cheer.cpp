#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int c[10050];
int n, p;
struct node{
	int v, u, w;
}edge[maxn];
bool cmp(node x, node y){
	return x.w < y.w;
}
int f[10500];
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]); 
}
int ans = 0x3f3f3f3f, tot;
void kruskal(){
	sort(edge + 1, edge + p + 1, cmp);
	for(int i = 1; i <= p; i++){
		int x = find(edge[i].u); int y = find(edge[i].v);
		if(x != y){
			ans += edge[i].w;
			f[x] = y;
			tot++;
		}
		if(tot == n - 1) break;
	}
}
int main(){
	cin>>n>>p;
	for(int i = 1; i <= n; i++){
		cin>>c[i];
		f[i] = i;
		ans = min(ans, c[i]);
	}
	int w;
	for(int i = 1; i <= p; i++){
		cin>>edge[i].u>>edge[i].v>>w;
		w = (w << 1) + c[edge[i].u] + c[edge[i].v];
		edge[i].w = w;
	}
	kruskal();
	cout<<ans;
	return 0;
}
