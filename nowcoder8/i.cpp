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
 
const int inf = 0x3f3f3f3f;
const int N = 3e5 + 50;
struct node {
    int v, cap, flow, nxt;
    node () {}
    node (int v, int cap, int flow, int nxt): v(v), cap(cap), flow(flow), nxt(nxt) {}
} edge[N * 10];
int head[N], tot;
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}
int dep[N];
void adde(int u, int v, int w) {
    edge[tot] = node(v, w, 0, head[u]);
    head[u] = tot++;
    edge[tot] = node(u, 0, 0, head[v]);
    head[v] = tot++;
}
int gap[N], cur[N];
void bfs(int s, int t) {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    queue<int> q;
    dep[t] = 0;
    q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (dep[v] != -1) continue;
            q.push(v);
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int S[N];
int sap(int s, int t, int n) {
    bfs(s, t);
    memcpy(cur, head, sizeof(head));
    int top = 0;
    int u = s;
    int ans = 0;
    while (dep[s] < n) {
        if (u == t) {
            int minn = inf;
            int inser;
            for (int i = 0; i < top; i++) {
                if (minn > edge[S[i]].cap - edge[S[i]].flow) {
                    minn = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            }
            for (int i = 0; i < top; i++) {
                edge[S[i]].flow += minn;
                edge[S[i] ^ 1].flow -= minn;
            }
            ans += minn;
            top = inser;
            u = edge[S[top] ^ 1].v;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; ~i; i = edge[i].nxt) {
            v = edge[i].v;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]) {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if (flag) {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int minn = n;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            if (edge[i].cap - edge[i].flow && dep[edge[i].v] < minn) {
                minn = dep[edge[i].v];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if (!gap[dep[u]]) return ans;
        dep[u] = minn + 1;
        gap[dep[u]]++;
        if (u != s) u = edge[S[--top] ^ 1].v;
    }
    return ans;
}
int main() {
    int t; in >> t;
    int cse = 0;
    while (t--) {
        init();
        int n; in >> n;
        map<int, int> mp;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int u, v;
            in >> u >> v;
            if (!mp.count(u)) mp[u] = ++cnt;
            if (!mp.count(v)) mp[v] = ++cnt;
            u = mp[u];
            v = mp[v];
            adde(i, u + n, 1);
            adde(i, v + n, 1);
        }
        for (int i = 1; i <= n; i++) {
            adde(0, i, 1);
        }
        for (int i = 1; i <= cnt; i++) {
            adde(i + n, n + cnt + 1, 1);
        }
        printf("Case #%d: %d\n", ++cse, sap(0, n + cnt + 1, n + cnt + 1));
    }
    return 0;
}