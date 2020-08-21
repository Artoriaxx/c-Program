#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

const int N = 505;
#define pii pair<int, int>
mt19937_64 rdn(time(0));
int n;
ull key[N];
struct tree {
    ull hs[N];
    int sz[N];
    vector<int> G[N];
    int rt = 0;
    vector<pii> f;
    void read() {
        for (int i = 1; i <= n; i++) {
            int x; in >> x;
            if (x == 0) rt = i;
            else {
                G[i].push_back(x);
                G[x].push_back(i);
            }
        }
        dfs(rt, 0);
        for (int i = 1; i <= n; i++) f.push_back(pii(sz[i], i));
        sort(f.begin(), f.end());
    }
    void dfs(int u, int fa) {
        sz[u] = 1;
        hs[u] = key[sz[u]];
        for (int v : G[u]) {
            if (v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
            hs[u] += key[sz[v]] * hs[v];
        }
    }
} t1, t2;
struct KM {
    int G[N][N];
    bool visx[N], visy[N];
    int lx[N], ly[N];
    int slack[N];
    int linker[N];
    int pre[N];
    const int inf = 1e9 + 50;
    int n;
    void bfs(int k) {
        int x, y = 0, yy = 0, delta;
        memset(pre, 0, sizeof(pre));
        fill(slack + 1, slack + n + 1, inf);
        linker[y] = k;
        while (1) {
            x = linker[y]; delta = inf; visy[y] = true;
            for (int i = 1; i <= n; i++) {
                if (!visy[i]) {
                    if (slack[i] > lx[x] + ly[i] - G[x][i]) {
                        slack[i] = lx[x] + ly[i] - G[x][i];
                        pre[i] = y;
                    }
                    if (slack[i] < delta) delta = slack[i], yy = i;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (visy[i]) lx[linker[i]] -= delta, ly[i] += delta;
                else slack[i] -= delta;
            }
            y = yy;
            if (linker[y] == -1) break;
        }
        while (y) linker[y] = linker[pre[y]], y = pre[y];
    }
    int calc(int nn) {
        n = nn;
        for (int i = 1; i <= n; i++) {
            lx[i] = ly[i] = 0;
            linker[i] = -1;
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         printf("%d ", G[i][j]);
        //     }
        //     puts("");
        // }
        for (int i = 1; i <= n; i++) {
            memset(visy, false, sizeof(visy));
            bfs(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (linker[i]) ans += G[linker[i]][i];
        }
        return ans;
    }
    
} km;
int dp[N][N];
int main() {
    in >> n;
    for (int i = 0; i <= n; i++) key[i] = rdn();
    t1.read(); t2.read();
    for (auto x : t1.f) {
        for (auto y : t2.f) {
            int u1 = x.second, u2 = y.second;
            if (t1.hs[u1] == t2.hs[u2]) {
                set<ull> val;
                map<ull, vector<int>> m1, m2;
                for (int v1 : t1.G[u1]) val.insert(t1.hs[v1]), m1[t1.hs[v1]].push_back(v1);
                for (int v2 : t2.G[u2]) m2[t2.hs[v2]].push_back(v2);
                int ans = 0;
                for (ull v : val) {
                    auto v1 = m1[v], v2 = m2[v];
                    for (int i = 0; i < v1.size(); i++) {
                        for (int j = 0; j < v2.size(); j++) {
                            km.G[i+1][j+1] = dp[v1[i]][v2[j]];
                        }
                    }
                    ans += km.calc(v1.size());
                }
                dp[u1][u2] = ans + (u1 == u2);
                //printf("%d %d %d %d\n", u1, u2, ans, dp[u1][u2]);
            }

        }
    }
    printf("%d\n", n - dp[t1.rt][t2.rt]);
    return 0;
}
