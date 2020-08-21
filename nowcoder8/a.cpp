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

const int N = 5e5 + 50;
#define pii pair<int, int>
map<pii, int> mp;
pii edge[N<<1];
int vis[N<<1];
int link[N];
int ans, num;



int f[N], sz[N];
stack<pii> s;
int find(int x) { return x == f[x] ? x : find(f[x]); }
int merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return 0;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    if (sz[x] >= 2 && sz[y]) ans--;
    f[y] = x;
    s.push(pii(x, y)); return 1;
}
void del(int len) {
    while (!s.empty() && (len--)) {
        int x = s.top().first, y = s.top().second;
        s.pop();
        if (sz[x] < sz[y]) swap(x, y);
        if (sz[x] >= 2 && sz[y]) ans++;
        sz[x] -= sz[y];
        f[y] = y;
    }
}

#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
vector<int> t[N<<2];
void update(int o, int l, int r, int ql, int qr, int id) {
    if (ql > qr) return;
    if (ql <= l && r <= qr) { t[o].push_back(id); return; }
    if (ql <= mid) update(ls, l, mid, ql, qr, id);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, id);
}
void query(int o, int l, int r) {
    int len = 0;
    for (int id : t[o]) {
        link[edge[id].second]++;
        if (link[edge[id].second] == 1) num--;
        len += merge(edge[id].first, edge[id].second);
    }
    if (l == r) {
        if (num) puts("-1");
        else printf("%d\n", ans);
        for (int id : t[o]) {
            link[edge[id].second]--;
            if (link[edge[id].second] == 0) num++;
        }
        del(len);
        return;
    }
    query(ls, l, mid); query(rs, mid + 1, r);
    for (int id : t[o]) {
        link[edge[id].second]--;
        if (link[edge[id].second] == 0) num++;
    }
    del(len);
}
int main() {
    int n, m, q; in >> n >> m >> q;
    int cnt = 0;
    num = ans = m;
    for (int i = 1; i <= n + m; i++) f[i] = i;
    for (int i = n + 1; i <= n + m; i++) sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        int k; in >> k;
        for (int j = 1; j <= k; j++) {
            int x; in >> x; x += n;
            mp[pii(i, x)] = ++cnt;
            edge[cnt] = pii(i, x);
            vis[cnt] = 1;
        }
    }
    for (int i = 1; i <= q; i++) {
        int u, v; in >> v >> u; v += n;
        if (!mp.count(pii(u, v))) {
            mp[pii(u, v)] = ++cnt;
            edge[cnt] = pii(u, v);
        }
        int id = mp[pii(u, v)];
        if (!vis[id]) vis[id] = i;
        else {
            update(1, 1, q, vis[id], i - 1, id);
            vis[id] = 0;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (vis[i]) update(1, 1, q, vis[i], q, i);
    }
    query(1, 1, q);
    return 0;
}
