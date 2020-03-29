#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
vector<int> G[N];
int fa[N][26];
int a[N];
int dep[N];
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for (auto v : G[u]) {
        if (v == f) continue;
        fa[v][0] = u;
        dfs(v, u);
    }
}
bool cmp(int a, int b) {
    return dep[a] < dep[b];
}
int n, m;
inline void init(){
	for (int i = 1; i <= 24; i++){
		for (int j = 1; j <= n; j++){
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
}
inline int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 24; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 24; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i]; y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main() {
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dep[0] = 0;
    dfs(1, 0);
    fa[1][0] = 1;
    init();
    for (int i = 1; i <= m; i++) {
        int k; scanf("%d", &k);
        int now = 1;
        bool flag = true;
        for (int j = 1; j <= k; j++) {
            scanf("%d", &a[j]);
        }
        sort(a + 1, a + k + 1, cmp);
        int nowf = 1;
        for (int j = 1; j <= k; j++) {
            int now = j;
            while (dep[a[now + 1]] == dep[a[j]] && now < k) {
                now++;
            }
            int x = fa[a[now]][0];
            for (int y = j; y <= min(now, k); y++) {
                if (fa[a[y]][0] != x) {
                    flag = false;
                }
            }
            if (lca(x, nowf) != nowf) flag = false;
            nowf = x;
            j = now;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}