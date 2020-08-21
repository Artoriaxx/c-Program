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

const int N = 1050;
int vis[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            int x; in >> x;
            vis[x]++;
        }
        bool flag = false;
        int ans;
        for (int i = 1; i <= m; i++) {
            int x; in >> x;
            if (vis[x]) {
                flag = true;
                ans = x;
            }
        }
        if (flag) {
            puts("YES");
            printf("1 %d\n", ans);
        }
        else puts("NO");
    }
    return 0;
}
