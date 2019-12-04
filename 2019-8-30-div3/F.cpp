#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
vector<int> G[N];
int a[N], b[N];
int dfn[N], low[N], vis[N], spe[N], sta[N], block, tmp, cnt;
void tarjan(int x) {
	dfn[x] = low[x] = ++tmp;
	sta[++cnt] = x, vis[x] = 1;
	for (int i = 0; i < G[x].size(); i++){
		int v = G[x][i];
		if (!dfn[v]){
			tarjan(v);
			low[x] = min(low[v], low[x]);
		}
		else if (vis[v]) low[x] = min(low[x], dfn[v]);
	}
	if (low[x] == dfn[x]){
		++block;
		int v;
		do {
			v = sta[cnt--];
			spe[v] = block;
			vis[v] = 0;
		} while (v != x);
	}
}
char ans[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i == 1) continue;
        G[a[i - 1]].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (i == 1) continue;
        G[b[i - 1]].push_back(b[i]);
    }
    tarjan(a[1]);
    int now = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (!vis[spe[a[i]]]) {
            vis[spe[a[i]]] = 1;
            now++;
        }
        ans[a[i]] = 'a' + min(now, 26) - 1;
    }
    if (now >= k) {
        puts("YES");
        printf("%s", ans + 1);
    }
    else puts("NO");
    return 0;
}