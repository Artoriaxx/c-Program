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

const int N = 15;
int a[N];
int vis[N];
int n;
void dfs(int s) {
    if (s > n) {
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        puts("");
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (!vis[i]) {
            vis[i] = 1;
            a[s] = i;
            dfs(s + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) vis[i] = 0;
        dfs(1);
    }
    return 0;
}
