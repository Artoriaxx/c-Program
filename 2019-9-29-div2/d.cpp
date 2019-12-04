#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
vector<int> G[N];
int vis[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, int> mp[N];
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = mp[b][a] = 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < G[1].size(); i++) {
        vis[G[1][i]] = 1;
    }
    int x;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) x = i;
    }
    for (int i = 0; i < G[x].size(); i++) {
        if (vis[G[x][i]]) vis[G[x][i]] = 2;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {

        }
    }
    
}