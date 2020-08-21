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

const int N = 50;
char tmp[N];
vector<int> G[N];
int vis[N];
bool flag;
void dfs(int u) {
    vis[u] = 1;
    if (u == 'm' - 'a') flag = true;
    if (flag) return;
    for (auto v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}
int main() {
    while (~scanf("%s", tmp + 1)) {
        for (int i = 0; i < 26; i++) G[i].clear(), vis[i] = 0;
        if (tmp[1] != '0') {
            int len = strlen(tmp + 1);
            G[tmp[1] - 'a'].push_back(tmp[len] - 'a');
        }
        else continue;
        while (scanf("%s", tmp + 1)) {
            if (tmp[1] != '0') {
                int len = strlen(tmp + 1);
                G[tmp[1] - 'a'].push_back(tmp[len] - 'a');
            }
            else break;
        }

        flag = false;
        dfs(1);
        if (flag) puts("Yes.");
        else puts("No.");
    }
    return 0;
}
