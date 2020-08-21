#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 5e4 + 50;
vector<int> G[N];
int n;
/*--------------------------------*/
int cnt;
int fa[N], son[N], sze[N], dep[N];
void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    sze[u] = 1;
    fa[u] = f; son[u] = 0;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sze[u] += sze[v]; 
        if (sze[v] > sze[son[u]]) son[u] = v;
    }
}
int top[N], pos[N];
void dfs2(int u, int f, int t) {
    top[u] = t;
    pos[u] = ++cnt;
    if (son[u]) dfs2(son[u], u, t);
    for (int v : G[u]) {
        if (v == f || v == son[u]) continue;
        dfs2(v, u, v);
    }
}
/*--------------------------------*/

/*--------------------------------*/
#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
ll sum[N<<2], add[N<<2];
void pushup(int o) { sum[o] = sum[ls] + sum[rs]; }
void pushdown(int o, int l, int r) {
    if (add[o]) {
        add[ls] += add[o];
        add[rs] += add[o];
        sum[ls] += add[o] * (mid - l + 1);
        sum[rs] += add[o] * (r - mid);
        add[o] = 0;
    }
}
void build(int o, int l, int r) {
    if (l == r) { sum[o] = 0; add[o] = 0; return; }
    sum[o] = 0; add[o] = 0;
    build(ls, l, mid); build(rs, mid + 1, r);
}
void update(int o, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        sum[o] += v * (r - l + 1);
        add[o] += v;
        return;
    }
    pushdown(o, l, r);
    if (ql <= mid) update(ls, l, mid, ql, qr, v);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, v);
    pushup(o);
}
ll query(int o, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) { return sum[o]; }
    pushdown(o, l, r);
    if (qr <= mid) return query(ls, l, mid, ql, qr);
    else if (ql > mid) return query(rs, mid + 1, r, ql, qr);
    else return query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr);
}
/*--------------------------------*/

/*--------------------------------*/
void change(int u, int v, int val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, pos[top[u]], pos[u], val);
        u = fa[top[u]];
    }
    if (pos[u] < pos[v]) swap(u, v);
    update(1, 1, n, pos[v], pos[u], val);
}
ll ask(int u, int v) {
    ll ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += query(1, 1, n, pos[top[u]], pos[u]);
        u = fa[top[u]];
    }
    if (pos[u] < pos[v]) swap(u, v);
    return ans + query(1, 1, n, pos[v], pos[u]);
}
/*--------------------------------*/
ll totw, cnt1;
ll d[N];
void init() {
    for (int i = 1; i <= n; i++) G[i].clear(), d[i] = 0;
    dep[0] = 0; cnt = 0;
    totw = cnt1 = 0;
    build(1, 1, n);
}
int main() {
    int t; in >> t;
    while (t--) {
        int q; in >> n >> q;
        init();
        for (int i = 1; i < n; i++) {
            int u, v; in >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 0, 1);
        while (q--) {
            int op, x; in >> op >> x;
            if (op == 1) {
                int w; in >> w;
                totw += w - dep[x];
                cnt1++;
                change(1, x, 2);
            }
            else if (op == 2) {
                ll v = totw + ask(1, x) - cnt1 * dep[x];
                if (d[x] < v) d[x] = v; 
            }
            else {
                printf("%lld\n", totw + ask(1, x) - cnt1 * dep[x] - d[x]);
            }
        }
    }
    return 0;
}
