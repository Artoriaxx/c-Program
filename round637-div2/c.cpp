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
int p[N];
int vis[N];
int a[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> p[i], vis[p[i]] = i, a[i] = 0;
        if (n == 1) {
            puts("Yes");
            continue;
        }
        int now = vis[1];
        a[vis[1]] = 1;
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            if (vis[i] != now + 1) {
                if (now + 1 > n || a[now + 1] == 1);
                else flag = false;
            }
            a[vis[i]] = 1;
            now = vis[i];
        }
        if (flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
