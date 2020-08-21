#include<bits/stdc++.h>
#define lc  u<<1
#define rc  u<<1|1
#define mid (t[u].l+t[u].r)/2
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
 
int N;
int ans[MAX];
vector<int> store;
 
vector<int> g[MAX];
int anc[MAX][20], dep[MAX], st[MAX], ed[MAX], nodeOf[MAX], dfnt;
void dfs(int u, int fa) {
    dep[u] = dep[anc[u][0] = fa] + 1, nodeOf[st[u] = ++dfnt] = u;
    for (int i = 1; i <= 19; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (auto &v: g[u])
        if (v != fa) dfs(v, u);
    ed[u] = dfnt;
}
//k级祖先, 倍增跳
int kthFa(int u, int k) { int bit = 0; while (k) { if (k & 1) u = anc[u][bit]; k >>= 1; bit++;} return u; }
 
struct SegmentTree {
    int mx, node, l, r;
    bool cover;
} t[MAX << 2];
void push_up(int u) {
    t[u].mx = 0;
    if (!t[lc].cover && t[lc].mx > t[u].mx) t[u].node = t[lc].node, t[u].mx = t[lc].mx;
    if (!t[rc].cover && t[rc].mx > t[u].mx) t[u].node = t[rc].node, t[u].mx = t[rc].mx;
}
void build(int u, int l, int r) {
    t[u].l = l, t[u].r = r;
    if (l == r) {
        t[u].mx = dep[t[u].node = nodeOf[l]];
        return;
    }
    build(lc, l, mid); build(rc, mid + 1, r);
    push_up(u);
}
void update(int u, int ql, int qr, int k) {
    if (ql <= t[u].l && t[u].r <= qr) {
        t[u].cover = k;
        return;
    }
    if (ql <= mid) update(lc, ql, qr, k);
    if (qr > mid) update(rc, ql, qr, k);
    push_up(u);
}
 
 
void init() {
    dfnt = 0;
    for (int i = 1; i <= N; i++) g[i].clear();
}
 
int main() {
 
    while (~scanf("%d", &N)) {
        init();
        for (int i = 2; i <= N; i++) {
            int x; scanf("%d", &x);
            g[x].push_back(i); g[i].push_back(x);
        }
        dep[0] = -1; dfs(1, 0);
        build(1, 1, dfnt);//按dfs序建立线段树
        for (int i = 1; i <= N; i++) ans[i] = N - 1;
        for (int nowans = N - 1; nowans >= 0; nowans--) {
            int cost = 0;
            store.clear();
            while (1) {
                cost++;
                if (t[1].mx <= nowans) break;//如果树中未覆盖的最大值<=ans, 那么就不需要再覆盖了
                int u = t[1].node;
                u = kthFa(u, nowans);//让最深的点u的贡献值变为nowans, 所以从u往上找nowans个点, 即u的nowans-th祖先
                store.push_back(u);//将覆盖的部分记录, 之后线段树清空
                update(1, st[u], ed[u], 1);//覆盖u的子树, 因为我们将u设为关键点, 且u中最深的点都满足<=nowans, 因此整个子树都满足
            }
            ans[cost] = nowans;//设cost个关键点的答案
            for (auto &i: store) update(1, st[i], ed[i], 0);//清空线段树
        }
        for (int i = 2; i <= N; i++) ans[i] = min(ans[i], ans[i - 1]);//如果设更少的关键点的答案能更小, 那答案就取小的
        ll sum = 0;
        for (int i = 1; i <= N; i++) sum += ans[i];
        printf("%lld\n", sum);
    }
 
    return 0;
}