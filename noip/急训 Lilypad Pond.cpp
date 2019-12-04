#include<bits/stdc++.h>
using namespace std;
int a[35][35];
int xi, yi, xt, yt;
int n, m, tx, ty;
int vis[35][35];
struct node{
	int x; int y; int ans;
} pot;
inline int check(int x, int y){
	return ((x <= n) && (x > 0) && (y <= m) && (y > 0));
}
int bfs(){//×î¶Ì¼È¿¼ÂÇbfs
	int dx[9] = {tx, -tx, -tx, tx, ty, ty, -ty, -ty};
	int dy[9] = {ty, ty, -ty, -ty, tx, -tx, -tx, tx};
	vis[xi][yi] = 1;
	pot.x = xi, pot.y = yi, pot.ans = 0;
	queue<node> q;
	q.push(pot);
	while (!q.empty()){
		node now = q.front(); q.pop();
		if (now.x == xt && now.y == yt) return now.ans;
		for (int i = 0; i < 8; i++){
			pot.x = now.x + dx[i], pot.y = now.y + dy[i], pot.ans = now.ans;
			if (check(pot.x, pot.y) && !vis[pot.x][pot.y] && (a[pot.x][pot.y] == 1 || a[pot.x][pot.y] == 4)){
				pot.ans++;
				vis[pot.x][pot.y] = 1;
				q.push(pot);
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d", &n, &m, &tx, &ty);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j] == 3) xi = i, yi = j;
			if (a[i][j] == 4) xt = i, yt = j;
		}
	}
	int ans = bfs();
	printf("%d", ans);
}
