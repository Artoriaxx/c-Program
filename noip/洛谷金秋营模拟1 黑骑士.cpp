#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
#define ll long long
#define p 19260817

using namespace std;

inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}

int n, m;

struct node{
	int v, next;
}edge[maxn * 4];
int num, head[maxn];
inline void adde(int u , int v){
	edge[++num].next = head[u];
	edge[num].v = v;
	head[u] = num;
}

int vis[maxn], fa[maxn], spe[maxn], belong[maxn], cnt;

void dfs(int u){ //dfs’“ª∑ 
	vis[u] = 1;
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v != fa[u]){
			if (!vis[v]){
				fa[v] = u;
				dfs(v);
			} 
			else if (!belong[v]){
				int f = u;
				spe[++cnt] = 1;
				while (1){
					belong[f] = cnt;
					if (f == v) break;
					f = fa[f];
				}
			}
		}
	}
}
ll f[maxn]; ll ans;
void dp(int u, int fa){
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].v;
		if (v != fa){
			dp(v, u);
			ans += (f[u] * (spe[u] ? 2 : 1) * f[v]) % p;
			f[u] += f[v] % p;
		}
	}
	if (spe[u]){
		ans += f[u] % p;
		f[u] = (2 * f[u] + 1) % p;
	}
}
int a[maxn * 4], b[maxn * 4];
int main(){
	n = getnum(); m = getnum();
	for (int i = 1; i <= m; i++){
		a[i] = getnum(), b[i] = getnum();
		adde(a[i], b[i]); adde(b[i], a[i]);
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
		if (!belong[i]) belong[i] = ++cnt;
	}
	memset(edge, 0, sizeof(edge));
	memset(head, 0, sizeof(head));
	num = 0;
	for (int i = 1; i <= m; i++){
		if (belong[a[i]] != belong[b[i]]){
			adde(belong[a[i]], belong[b[i]]);
			adde(belong[b[i]], belong[a[i]]);
		}
	}
	dp(1, 0);
	cout << ans % p;
	return 0;
}
