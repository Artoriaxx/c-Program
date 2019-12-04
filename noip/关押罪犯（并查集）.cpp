#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 100005; 
const int maxn = 20005;
int getnum(){
	int ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct node{
	int u, v, c;
}a[maxm];
int cmp(node x, node y){
	return x.c > y.c;
}
int fa[maxn], opp[maxn];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int x1 = find(x), y1 = find(y);
	if(x1 != y1) fa[x1] = y1;
}
int main(){
	int n, m;
	n = getnum(); m = getnum();
	for(int i = 1; i <= m; i++){
		a[i].u = getnum(); a[i].v = getnum(); a[i].c = getnum();
	}
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int u = a[i].u, v = a[i].v;
		int x = find(u), y = find(v);
		if(x == y){
			printf("%d", a[i].c);
			return 0;
		}
		if(opp[u] == 0) opp[u] = v;
		else merge(v, opp[u]);
		if(opp[v] == 0) opp[v] = u;
		else merge(u, opp[v]);
	}
	printf("0");
	return 0;
}
