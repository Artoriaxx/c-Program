#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
vector<int> G[N];
int vis[N];
int dfs(int u) {
    int ans = u;
    for (auto v : G[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            ans = dfs(v);
            break;
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int now = 1;
    vis[now] = 1;
    while (1) {
        int x = dfs(now);
        if (now == x) break;
        int y = dfs(now);
        cout << "? " << y << " " << x << endl;
        cin >> now;
    }
    cout << "! " << now << endl;
    return 0;
}