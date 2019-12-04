#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll b[65], p[65];
    int cnt, flag;
    node() {
        memset(p, 0, sizeof(p));
        memset(b, 0, sizeof(b));
        cnt = flag = 0;
    }
    bool insert(ll x) {
        for (int i = 62; i >= 0; i--) {
            if (x & (1LL << i)) {
                if (b[i]) {
                    x ^= b[i];
                }
                else {
                    b[i] = x;
                    return true;
                }
            }
        }
        flag = 1;
        return false;
    }
    ll qmax(ll base) {
        ll res = base;
        for (int i = 62; i >= 0; i--) {
            if ((res ^ b[i]) > res) res ^= b[i];
        }
        return res;
    }
    ll qmin() {
        if (flag) return 0;
        for (int i = 0; i <= 62; i++) {
            if (b[i]) return b[i];
        }
        return 0;
    }
    void rebuild() {
        for (int i = 62; i >= 1; i--) {
            if (b[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    if (b[i] & (1LL << j)) b[i] ^= b[j];
                }
            }
        }
        for (int i = 0; i <= 62; i++) {
            if (b[i]) p[cnt++] = b[i];
        }
    }
    ll kth(ll k) {
        if (flag) --k;
        if (k == 0) return 0;
        ll res = 0;
        if (k >= (1LL << cnt)) return -1;
        for (int i = 0; i < cnt; i++) {
            if (k & (1LL << i)) res ^= p[i];
        }
        return res;
    }
} lis;
node merge(node n1, node n2) {
    node res = n1;
    for (int i = 0; i <= 62; i++) {
        if (n2.b[i]) res.insert(n2.b[i]);
    }
    res.flag = n1.flag | n2.flag;
    return res;
}
struct edge {
    int v; ll w;
    edge(int v = 0, ll w = 0): v(v), w(w) {}
};
const int N = 5e4 + 10;
vector<edge> G[N];
ll a[N];
bool vis[N];
void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i].v;
        if (vis[v]) lis.insert(a[u] ^ a[v] ^ G[u][i].w);
        else {
            a[v] = a[u] ^ G[u][i].w;
            dfs(v);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }
    dfs(1);
    printf("%lld\n", lis.qmax(a[n]));
    return 0;
}