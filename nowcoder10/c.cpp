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
struct node {
    int u, v, w;
} edge[N];
multiset<int> st[N];
ll sum[N];
ll ans = 0;
int calc(int u) {
    int mx = *(--st[u].end());
    if (2ll * mx >= sum[u]) return 2 * mx - sum[u];
    else return sum[u] & 1;
}
void update(int p, int w) {
    int u = edge[p].u, v = edge[p].v;
    ans -= calc(u); ans -= calc(v);
    sum[u] += w - edge[p].w; sum[v] += w - edge[p].w;
    st[u].erase(st[u].lower_bound(edge[p].w)); st[u].insert(w);
    st[v].erase(st[v].lower_bound(edge[p].w)); st[v].insert(w);
    ans += calc(u); ans += calc(v);
    edge[p].w = w;
}
int main() {
    int n, q; in >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w; in >> u >> v >> w;
        edge[i] = {u, v, w};
        sum[u] += w; sum[v] += w;
        st[u].insert(w); st[v].insert(w);
    }
    
    for (int i = 1; i <= n; i++) ans += calc(i);
    printf("%lld\n", ans / 2);
    while (q--) {
        int p, w; in >> p >> w;
        update(p, w);
        printf("%lld\n", ans / 2);
    }
    return 0;
}
