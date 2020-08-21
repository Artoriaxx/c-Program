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

const int N = 1e5 + 50;
int a[N];
struct node {
    int v,  w;
    node(int v = 0, int w = 0): v(v), w(w) {}
};
vector<node> G[N];
int cnt = 0;
void dfs(int u, int fa) {
    for (auto nx : G[u]) {
        if (nx.v == fa) continue;
        a[nx.v] = a[u] ^ nx.w;
        dfs(nx.v, u);
    }
}
int trie[N << 5][2];
int tot = 0;
void ins(int x) {
    int rt = 0;
    for (int i = 30; i >= 0; i--) {
        int now = (x >> i) & 1;
        if (!trie[rt][now]) trie[rt][now] = ++tot;
        rt = trie[rt][now];
    }
}
int qry(int x) {
    int ans = 0, rt = 0;
    for (int i = 30; i >= 0; i--) {
        int now = (x >> i) & 1;
        if (trie[rt][now]) rt = trie[rt][now];
        else {
            rt = trie[rt][now ^ 1];
            ans |= (1 << i);
        }
    }
    return ans;
}
ll ans = 0;
void calc(int l, int r, int dep) {
    if (dep < 0 || l >= r) return;
    int mid = l - 1;
    while (mid < r && !((a[mid + 1] >> dep) & 1)) mid++;
    calc(l, mid, dep - 1);
    calc(mid + 1, r, dep - 1);
    if (mid == l - 1 || mid == r) return;
    tot = 0;
    for (int i = l; i <= mid; i++) ins(a[i]);
    int res = 0x7fffffff;
    for (int i = mid + 1; i <= r; i++) res = min(res, qry(a[i]));
    ans += res;
    for (int i = 0; i <= tot; i++) trie[i][0] = trie[i][1] = 0;
}
int main() {
    int n; in >> n;
    for (int i = 1; i < n; i++) {
        int u, v; ll w;
        in >> u >> v >> w;
        u++; v++;
        G[u].push_back(node(v, w));
        G[v].push_back(node(u, w));
    }
    dfs(1, 0);
    sort(a + 1, a + n + 1);
    calc(1, n, 30);
    printf("%lld\n", ans);
    return 0;
}
