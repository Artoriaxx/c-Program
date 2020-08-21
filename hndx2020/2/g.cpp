#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 50;
string s[N];
struct node {
    string fname, lname, fa, ch;
} a[N];
vector<int> G[N];
map<string, int> mp;
int in[N], vis[N];
int d[N];
void dfs(int u, int &d1, int &r) {
    d1 = max(d1, d[u]);
    vis[u] = 1;
    r++;
    for (auto v : G[u]) {
        if (vis[v]) continue;
        dfs(v, d1, r);
    }
}
int main() {
    int n; cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin, s[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string now = "";
        int cntt = 0;
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == ' ') {
                if (cntt == 0) a[i].fname = now;
                if (cntt == 1) a[i].lname = now;
                cntt++;
                now = "";
                continue;
            }
            now = now + s[i][j];
        }
        a[i].fa = now;
        a[i].fa = a[i].fname + a[i].fa;
        a[i].ch = a[i].fname + a[i].lname;
        if (!mp.count(a[i].fa)) mp[a[i].fa] = ++cnt;
        if (!mp.count(a[i].ch)) mp[a[i].ch] = ++cnt;
        G[mp[a[i].ch]].push_back(mp[a[i].fa]);
        in[mp[a[i].fa]]++;
    }
    queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (in[i] == 0) q.push(i), vis[i] = 1;
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            d[v] = max(d[v], d[u] + 1);
            ans = max(ans, d[v]);
            in[v]--;
            if (in[v] == 0) q.push(v), vis[v] = 1;
        }
    }

    for (int i = 1; i <= cnt; i++) {
        if (vis[i] == 0) {
            int d1 = 0, r = 0;
            dfs(i, d1, r);
            ans = max(ans, d1 + r);
        }
    }
    printf("%d\n", ans);
    return 0;
}
