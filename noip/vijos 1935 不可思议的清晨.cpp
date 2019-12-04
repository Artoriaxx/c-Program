#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll getnum(){
	ll ans = 0; char c; bool flag = false;
	while(!isdigit(c = getchar()) && c != '-');
	if(c == '-') flag = true; else ans = c - '0';
	while(isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int n, u, v; ll w, p[maxn];
struct node{
	int v, next; ll w;
}e[maxn * 2];
int num, head[maxn];
inline void adde(int u, int v, int w){
	e[++num].next = head[u];
	e[num].v = v;
	e[num].w = w;
	head[u] = num;
}
ll dep[maxn], dis[maxn], s[maxn];
int f[maxn][22];
void build(int x, int fa){
	s[x] = p[x];
	for(int i = head[x]; i; i = e[i].next){
		int v = e[i].v;
		if(v == fa) continue;
		f[v][0] = x;
		dep[v] = dep[x] + 1;
		dis[v] = dis[x] + e[i].w;
		build(v, x);
		s[x] += s[v];
	}
}

inline void init(){
	for(int j = 1; j <= 20; j++){
		for(int i = 1; i <= n; i++){
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i--){
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}
int main(){
	n = getnum();
	for(int i = 1; i < n; i++){
		u = getnum(), v = getnum(), w = getnum();
		adde(u, v, w);
		adde(v, u, w);
	}
	for(int i = 1; i <= n; i++){
		p[i] = getnum();
	}
	build(1, 0);
	init();
	int q;
	q = getnum();
	int x, y;
	for(int i = 1; i <= q; i++){
		x = getnum(); y = getnum();
		ll ansx; ll ansy;
		int t = lca(x, y);
		if(dis[x] - dis[t] == dis[y] - dis[t]){
			int tmp = x;
			for(int i = 20; i >= 0; i--){
				if(dep[f[tmp][i]] > dep[t]) tmp = f[tmp][i];
			}
			ansx = s[tmp];
			tmp = y;
			for(int i = 20; i >= 0; i--){
				if(dep[f[tmp][i]] > dep[t]) tmp = f[tmp][i];
			}
			ansy = s[tmp];
			cout<<ansx<<" "<<ansy<<endl;
		}
		else if(dis[x] - dis[t] > dis[y] - dis[t]){
			int tmp = x;
			for(int i = 20; i >= 0; i--){
				if((dep[f[tmp][i]] > dep[t]) && (dis[f[tmp][i]] - dis[t] + dis[y] - dis[t]) > (dis[x] - dis[f[tmp][i]]))
				tmp = f[tmp][i];
			}
			ansx = s[tmp];
			int tmpx = tmp; int tmpy = f[tmpx][0];
			for(int i = 20; i >= 0; i--){
				if((dep[f[tmpy][i]] > dep[t]) && (dis[tmpx] == dis[tmpy])){
					tmpy = f[tmpy][i];
				}
			}
			for(int i = 20; i >= 0; i--){
				if(dep[f[tmp][i]] > dep[tmpy]) tmp = f[tmp][i];
			}
			ansy = s[1] - s[tmp];
			cout<<ansx<<" "<<ansy<<endl;
		}
		else{
			int tmp = y;
			for(int i = 20; i >= 0; i--){
				if((dep[f[tmp][i]] > dep[t]) && (dis[f[tmp][i]] - dis[t] + dis[x] - dis[t]) > (dis[y] - dis[f[tmp][i]]))
					tmp = f[tmp][i];
			}
			int tmpy = tmp;
			ansy = s[tmpy];
			int tmpx = f[tmpy][0];
			for(int i = 20; i >= 0; i--){
				if((dep[f[tmpx][i]] > dep[t]) && (dis[tmpx] == dis[tmpy])){
					tmpx = f[tmpx][i];
				}
			}
			for(int i = 20; i >= 0; i--){
				if(dep[f[tmp][i]] > dep[tmpx]) tmp = f[tmp][i];
			}
			ansx = s[1] - s[tmp];
			cout<<ansx<<" "<<ansy<<endl;
		}
	}
	return 0;
}
