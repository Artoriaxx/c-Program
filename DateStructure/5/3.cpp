#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define N 100050
using namespace std;
vector<int> G[N];
int deg[N];
int ans[N];
int main() {
	freopen("3.txt","r", stdin);
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			deg[b]++;
			G[a].push_back(b);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) q.push(i), ans[++cnt] = i;
		}
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i];
				deg[v]--;
				if (deg[v] == 0) q.push(v), ans[++cnt] = v;;
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (deg[i] > 0) {
				flag = false;
				break;
			}
		}
		if (!flag) printf("Wrong\n");
		else {
			printf("Correct\n");
			for (int i = 1; i <= cnt; i++) {
				printf("%d ", ans[i]);
			}
		}
	}
	return 0;
}