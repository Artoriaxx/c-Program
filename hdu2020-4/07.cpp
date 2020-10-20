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

const int N = 4e5 + 50;
struct node {
	int u, v, cap, nxt;
	node () {}
	node (int u, int v, int cap, int nxt): u(v), v(v), cap(cap), nxt(nxt) {}
} edge[N * 10];
int head[N], tot;
void init() {
	memset(head, -1, sizeof(head));
	tot = 0;
}
int dep[N];
void adde(int u, int v, int w) {
	edge[tot] = node(u, v, w, head[u]);
	head[u] = tot++;
	edge[tot] = node(v, u, 0, head[v]);
	head[v] = tot++;
}
bool bfs(int s, int t) {
    queue<int> q;
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (edge[i].cap > 0 && dep[v] == -1) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[t] > 0;
}
int dfs(int u, int t, int f) {
    if (u == t) return f;
    int w, used = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        int cap = edge[i].cap;
        if (cap && dep[v] == dep[u] + 1) {
            w = f - used;
            w = dfs(v, t, min(w, cap));
            edge[i].cap -= w;
            edge[i ^ 1].cap += w;
            used += w;
            if (used == f) return f;
        }
    }
    if (!used) dep[u] = -1;
    return used;
}
const int inf = 0x3f3f3f3f;
int dinic(int s, int t) {
    int maxflow = 0;
    while (bfs(s, t)) {
       maxflow += dfs(s, t, inf);
    }
    return maxflow;
}
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        map<int, int> mp1, mp2;
        mp1.clear(), mp2.clear();
        int cnt1 = 0, cnt2 = 0;
        init();
        for (int i = 1; i <= n; i++) {
            int t, x;
            in >> t >> x;
            if (!mp1.count(t + x)) mp1[t + x] = ++cnt1;
            if (!mp2.count(t - x)) mp2[t - x] = ++cnt2;
            int p1 = mp1[t + x];
            int p2 = mp2[t - x];
            adde(p1, p2 + n, 1);
        }
        for (int i = 1; i <= cnt1; i++) adde(0, i, 1);
        for (int i = 1; i <= cnt2; i++) adde(i + n, 2 * n + 1, 1);
        printf("%d\n", dinic(0, 2 * n + 1));
    }
    return 0;
}
