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
int a[N], b[N], c[N];
int cnt[N][2][2];
vector<int> G[N];
void dfs1(int u, int f) {
    cnt[u][b[u]][c[u]]++;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs1(v, u);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cnt[u][i][j] += cnt[v][i][j];
            }
        }
    }
}
ll ans = 0;
void dfs(int u, int f, int val) {
    for (int v : G[u]) {
        if (v == f) continue;
        cnt[u][1][0] -= cnt[v][1][0];
        cnt[u][0][1] -= cnt[v][0][1];
        if (cnt[v][1][0] != cnt[v][0][1]) {
            int x = abs(cnt[v][1][0] - cnt[v][0][1]);
            ans += 1ll * val * x;
            if (cnt[v][1][0] > cnt[v][0][1]) {
                cnt[v][1][0] -= x;
            }
            else {
                cnt[v][0][1] -= x;
            }
        }
        dfs(v, u, min(val, a[v]));
    }
    ans += 1ll * val * (cnt[u][1][0] + cnt[u][0][1]);
}
int main() {
    int n; in >> n;
    for (int i = 1; i <= n; i++) {
        in >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; in >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    if (cnt[1][0][1] != cnt[1][1][0]) {
        puts("-1");
        return 0;
    }
    dfs(1, 0, a[1]);
    printf("%lld\n", ans);
    return 0;
}
