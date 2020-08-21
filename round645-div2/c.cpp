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
int aa[N][N];
int sum[N][N];
int vis[1000000];
int ans = 0;
int tans = 0;
void dfs(int a, int b, int c, int d, int now) {
    if (a > c || b > d) return;
    if (a == c && b == d) {
        if (!vis[now]) {
            vis[now] = 1;
            ans++;
        }
        tans++;
        return;
    }
    dfs(a + 1, b, c, d, now + aa[a + 1][b]);
    dfs(a, b + 1, c, d, now + aa[a][b + 1]);
}
int main() {
    // int n = 1000;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (j == 1) aa[i][j] = aa[i - 1][j] + i;
    //         else aa[i][j] = aa[i][j - 1] + i + j - 2;
    //     }
    // }
    int t; in >> t;
    while (t--) {
        int x1, y1, x2, y2;
        in >> x1 >> y1 >> x2 >> y2;
        int len1 = x2 - x1;
        int len2 = y2 - y1;
        int mn = min(len1, len2);
        int p = abs(len1 - len2);
        ll mans = 1ll * mn * mn + 1;
        mans += 1ll * p * mn;
        printf("%lld\n", mans);
    }
    return 0;
}
