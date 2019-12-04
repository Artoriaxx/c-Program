#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1060 
#define re register int
using namespace std;
inline int getnum(){
	char c; bool flag = false; int ans = 0;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int n, m, e;
struct node{
	int v, next;
}edge[maxn * maxn];
int head[maxn * 2], num;
inline void adde(int u, int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}
int check[maxn], matching[maxn];
bool dfs(int u, int tmp){
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (check[v] != tmp){
			check[v] = tmp;
			if (matching[v] == -1 || dfs(matching[v], tmp)){
				matching[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	n = getnum(), m = getnum(), e = getnum();
	for (re i = 1; i <= e; i++){
		int a = getnum(), b = getnum();
		if (a > n || b > m) continue;
		adde(a, b);
	}
	int ans = 0;
	memset(matching, -1, sizeof(matching));
	for (int i = 1; i <= n; i++){
		if (dfs(i, i))
			ans++;
	}
	printf("%d", ans);
	return 0;
}
