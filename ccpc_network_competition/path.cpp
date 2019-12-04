#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 50;
struct node {
    int v; ll w;
    node (int v = 0, int w = 0): v(v), w(w) {}
    bool operator < (const node &b) const {
        return w < b.w;
    }
};
vector<node> G[N];
struct Edge {
    int u, v; ll w;
    int id;
    Edge(int u = 0, int v = 0, ll w = 0, int id = 0): u(u), v(v), w(w), id(id) {}
    bool operator < (const Edge &b) const {
        if (w == b.w)
            if (u == b.u)
                if (v == b.v)
                    return id < b.id;
                else return v < b.v;
            else return u < b.u;
        else return w < b.w;
    }
    bool operator == (const Edge &b) const {
        return w == b.w && u == b.u && v == b.v && id == b.id;
    }
};
int Q[N];
ll ans[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++) G[i].clear();
        set<Edge> st; st.clear();
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(node(v, w));
            st.insert(Edge(u, v, w, ++cnt));
        }
        for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
        int maxk = 0;
        for (int i = 1; i <= q; i++) {
            scanf("%d", &Q[i]);
            maxk = max(maxk, Q[i]);
        }
        while (st.size() > maxk) st.erase(st.end());
        for (int i = 1; i <= maxk; i++) {
            Edge now = *st.begin();
            st.erase(st.begin());
            ans[i] = now.w;
            if (i == maxk) break;
            int u = now.v;
            for (int j = 0; j < G[u].size(); j++) {
                int v = G[u][j].v;
                ll w = G[u][j].w;
                if (i + st.size() < maxk) st.insert(Edge(now.u, v, now.w + w, ++cnt));
                else {
                    set<Edge>::iterator it = st.end(); it--;
                    Edge last = *it;
                    if (now.w + w < last.w) {
                        st.erase(it);
                        st.insert(Edge(u, v, now.w + w, ++cnt));
                    }
                    else break;
                }
            }
        }
        for (int i = 1; i <= q; i++) printf("%lld\n", ans[Q[i]]);
    }
    return 0;
}