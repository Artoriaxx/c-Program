#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 2005
using namespace std;
typedef long long ll;
int n, m;
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	else {
		fa[x] = y;
		return true;
	}
}
bool same(int x, int y) {
	x = find(x), y = find(y);
	return x == y;
}
struct node {
	int u, v, w;
	bool operator < (const node &b) const {
		return w < b.w;
	}
} edge[N];
int main() {
	freopen("2.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		char ch[2];
		int cnt = 0;
		for (int i = 0; i <= 30; i++) {
			fa[i] = i;
		}
		for (int i = 1; i < n; i++) {
			scanf("%s", ch);
			int k;
			scanf("%d", &k);
			for (int i = 1; i <= k; i++) {
				char ch1[2];
				int val;
				scanf("%s%d", ch1, &val);
				edge[++cnt].u = ch[0] - 'A';
				edge[cnt].v = ch1[0] - 'A';
				edge[cnt].w = val;
			}
		}
		sort (edge + 1, edge + cnt + 1);
		int ans = 0;
		for (int i = 1; i <= cnt; i++) {
			if (merge(edge[i].u, edge[i].v)) {
				ans += edge[i].w;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}