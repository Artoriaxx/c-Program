#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
	int u, v, nxt;
	node() {}
	node(int u, int v, int nxt): u(u), v(v), nxt(nxt) {}
} edge[N * 2];
int head[N];
int tot;
void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}
void adde(int u, int v) {
	edge[tot] = node(u, v, head[u]);
	head[u] = tot++;
	edge[tot] = node(v, u, head[v]);
	head[v] = tot++;
}
void build() {
	FILE *fp;
	fp = fopen("1.txt", "r");
	int n, m;
	init();
	fscanf(fp, "%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		fscanf(fp, "%d%d", &u, &v);
		adde(u, v);
	}
	fclose(fp);
}
int vis[N];
void dfs1(int u) {
	printf("%d ", u);
	vis[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (!vis[v]) {
			dfs1(v);
		}
	}
}
void dfs(int u) {
	printf("dfs: \n");
	dfs1(u);
	printf("\n");
}

void bfs(int u) {
	printf("bfs: \n");
	queue<int> q;
	q.push(u);
	memset(vis, 0, sizeof(vis));
	vis[u] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = head[now]; ~i; i = edge[i].nxt) {
			if (!vis[edge[i].v]) q.push(edge[i].v);
			vis[edge[i].v] = 1;
		}
	}
	printf("\n");
}
int main() {
	int q;
	while (scanf("%d", &q) && q) {
		switch(q) {
			case 1: build(); break;
			case 2: dfs(1); break;
			case 3: bfs(1); break;
		}
	}
	
	return 0;
}