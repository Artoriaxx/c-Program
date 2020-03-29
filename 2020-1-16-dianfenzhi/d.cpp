#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
vector<int> G[N];
const int inf = 1e9;
int sze[N];
int msze[N];
int root;
int vis[N];
int S;
int maxx;
void getroot(int u, int f) {
    sze[u] = 1;
    msze[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (vis[v] || v == f) continue;
        getroot(v, u);
        sze[u] += sze[v];
        msze[u] = max(msze[u], sze[v]);
    }
    msze[u] = max(msze[u], S - sze[u]);
    if (msze[u] < maxx) {
        maxx = msze[u];
        root = u;
    }
}
typedef long long ll;
int c[N];
ll a[5050];
int k;
vector<int> sta;
void getsta(int u, int f, int s) {
    a[s]++; sta.push_back(s);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (vis[v] || v == f) continue;
        getsta(v, u, s | (1 << c[v]));
    }
}

ll calc(int u, int s) {
    sta.clear();
    memset(a, 0, sizeof(a));
    getsta(u, 0, s);
    ll ans = 0;
    for (int i = 0; i < sta.size(); i++) {
        a[sta[i]]--;
        ans += a[(1 << k) - 1];
        for (int j = sta[i]; j; j = (j - 1) & sta[i]) {
            ans += a[((1 << k) - 1) ^ j];
        }
        a[sta[i]]++;
    }
    return ans;
}
ll ans = 0;
void dfs(int u) {
    vis[u] = 1;
    ans += calc(u, 1 << c[u]);
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (vis[v]) continue;
        ans -= calc(v, (1 << c[v]) | (1 << c[u]));
        S = sze[v];
        root = 0;
        maxx = inf;
        getroot(v, u);
        dfs(root);
    }
}
int main() {
    int n;
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            scanf("%d", &c[i]);
            c[i]--;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (k == 1) {//别忘了特判
            printf("%lld\n", (ll)n * n);
            continue;
        }
        memset(vis, 0, sizeof(vis));//别忘清空vis!!
        ans = 0;
        S = n;
        root = 0;
        maxx = inf;
        getroot(1, 0);
        dfs(root);
        printf("%lld\n", ans);
    }
    
    return 0;
}