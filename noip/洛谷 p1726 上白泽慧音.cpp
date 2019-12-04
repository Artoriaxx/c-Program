#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 50005;
const int maxm = 5005;
struct node{
	int v, next;
}edge[maxn * 2];
int num, head[maxm];
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int dfn[maxm], low[maxm], tmp, cnt, sta[maxm], p;
bool vis[maxm];
int it;
vector<int> umi[maxm];
void tarjan(int x){
	dfn[x] = ++tmp;
	low[x] = tmp;
	vis[x] = true;
	sta[++p] = x;
	for (int i = head[x]; i; i = edge[i].next){
		int v = edge[i].v;
		if (!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if (vis[v]){
			low[x] = min(low[x], dfn[v]);
		}
	}
	int y;
	if (low[x] == dfn[x]){
		it++;
		do {
			y = sta[p--];
			vis[y] = false;
			umi[it].push_back(y);
		} while (x != y);
	}
}
int getnum(){
	int ans = 0; bool flag = false; char c;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int main(){
	int n, m;
	n = getnum(); 
	m = getnum();
	int type, yi, er;
	for(int i = 1; i <= m; i++){
		yi = getnum(); er = getnum(); type = getnum();
		if(type == 1) adde(yi, er);
		else{
			adde(yi, er);
			adde(er, yi);
		}
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	int max1 = 0, point;
	for(int i = 1; i <= it; i++){
		int size = umi[i].size();
		if(size > max1){
			max1 = size;
			point = i;
		}
	}
	sort(umi[point].begin(), umi[point].end());
	cout<<max1<<endl;
	for(int i = 0; i < umi[point].size(); i++){
		cout<<umi[point][i]<<" ";
	}
	return 0;
}
