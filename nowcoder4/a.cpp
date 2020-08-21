#include <bits/stdc++.h>
#define lson (o << 1)
#define rson (o << 1 | 1)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
vector<int> G[N];
int in[N], out[N];
int fa[N][20];
int point[N];
int dep[N];
int cnt = 0;
void dfs(int u, int f) {
    in[u] = ++cnt;
    point[cnt] = u;
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
    out[u] = cnt;
}
struct node {
    int mx, cov, depst;
} tree[N << 2];
void pushup(int o) {
    tree[o].mx = 0;
    if (!tree[lson].cov && tree[lson].mx > tree[o].mx) {
        tree[o].mx = tree[lson].mx;
        tree[o].depst = tree[lson].depst;
    }
    if (!tree[rson].cov && tree[rson].mx > tree[o].mx) {
        tree[o].mx = tree[rson].mx;
        tree[o].depst = tree[rson].depst;
    }
}
void build(int o, int l, int r) {
    if (l == r) {
        tree[o].mx = dep[point[l]]; tree[o].depst = point[l]; tree[o].cov = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
    pushup(o);
}
void update(int o, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        tree[o].cov = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(lson, l, mid, ql, qr, v);
    if (qr > mid) update(rson, mid + 1, r, ql, qr, v);
    pushup(o);
}

void init(int n) {
    cnt = 0;
    dep[0] = -1;
    dfs(1, 0);
    build(1, 1, n);
    for (int i = 1; i <= 19; i++) {
        for (int u = 1; u <= n; u++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
    }
}
int kfa(int u, int k) {
    for (int i = 19; i >= 0; i--) {
        if (k & (1 << i)) u = fa[u][i];
    }
    return u;
}
int ans[N];
int main() {
    int n; 
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) G[i].clear(), ans[i] = n - 1;
        for (int i = 2; i <= n; i++) {
            int x; scanf("%d", &x);
            G[i].push_back(x);
            G[x].push_back(i);
        }
        init(n);
        ll res = 0;
        for (int dis = 0; dis < n; dis++) {
            int k = 0;
            vector<int> tmp; tmp.clear();
            while (1) {
                k++;
                if (tree[1].mx <= dis) break;
                int u = tree[1].depst;
                u = kfa(u, dis);
                tmp.push_back(u);
                update(1, 1, n, in[u], out[u], 1);
            }
            for (int u : tmp) update(1, 1, n, in[u], out[u], 0);
            ans[k] = min(ans[k], dis);
        }
        for (int i = 2; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]), res += ans[i];
        res += ans[1];
        printf("%lld\n", res);
    }
    return 0;
}
