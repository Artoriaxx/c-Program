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

const int N = 2e5 + 50;
int a[N];
int fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
struct node {
    int v; ll w;
    node(int v = 0, ll w = 0): v(v), w(w) {};
};
vector<node> G[N];
const ll p = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll dis0[N],dis1[N],cnt0[N],cnt1[N];
ll ans;
void dfs(int x, int f) {
    for (auto e : G[x]) {
        if (e.v == f)continue;
        dfs(e.v, x);
        dis0[x] = (dis0[x] + dis0[e.v] + e.w * cnt0[e.v] % p) % p;
        dis1[x] = (dis1[x] + dis1[e.v] + e.w * cnt1[e.v] % p) % p;
        cnt0[x] += cnt0[e.v];
        cnt1[x] += cnt1[e.v];
    }
    if (a[x]) cnt1[x]++;
    else cnt0[x]++;
    for (auto e : G[x]) {
        if (e.v == f) continue;
        ans = (ans + (dis0[e.v] + e.w * cnt0[e.v] % p) % p * (cnt1[x] - cnt1[e.v]) % p) % p;
        ans = (ans + (dis1[e.v] + e.w * cnt1[e.v] % p) % p * (cnt0[x] - cnt0[e.v]) % p) % p;
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        ans = 0;
        memset(dis0, 0, sizeof(dis0));
        memset(dis1, 0, sizeof(dis1));
        memset(cnt0, 0, sizeof(cnt0));
        memset(cnt1, 0, sizeof(cnt1));
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) in >> a[i], fa[i] = i;
        for (int i = 1; i <= m; i++) {
            int u, v; in >> u >> v;
            int x = find(u), y = find(v);
            if (x != y) {
                G[u].push_back(node(v, qpow(2, i)));
                G[v].push_back(node(u, qpow(2, i)));
                fa[y] = x;
            }
        }
        dfs(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}