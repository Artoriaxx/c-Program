/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-12 21:38:20
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-12 23:50:40
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ios {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x) {
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
vector<int> G[N];
int dep[N];
int num[N][2];
bool flag = true;
void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == f) continue;
        dfs1(v, u);
        num[u][0] += num[v][1];
        num[u][1] += num[v][0];
        if (num[u][0] > 0 && num[u][1] > 0) {
            flag = false;
        }
    }
}
int vis[N];
int sz[N];
int ans = 0;
void dfs2(int u, int f) {
    sz[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == f) continue;
        dfs2(v, u);
        sz[u] += sz[v];
        if (sz[v] == 1) {
            if (vis[u] == 0) {
                ans++;
                vis[u] = 1;
            }
        }
        else ans++;
    }
}
int main() {
    int n; in >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        in >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (n == 2) {
        printf("1 1\n");
        return 0;
    }
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 1) {
            rt = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) {
            num[i][0] = 1;
            num[i][1] = 0;
        }
    }
    dep[rt] = 0;
    dfs1(rt, 0);
    if (flag) printf("1 ");
    else printf("3 ");
    flag = true;
    dfs2(rt, 0);
    printf("%d\n", ans);
    return 0;
}
