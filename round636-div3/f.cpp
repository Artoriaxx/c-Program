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

const int N = 250;
int a[N][N];
int ans[N];
int vis[N];
int b[N];
int c[N];
int n;
int check(int x) {
    for (int i = 1; i <= n; i++) vis[i] = 0;
    ans[1] = x;
    vis[x] = 1;
    for (int pos = 2; pos <= n; pos++) {
        bool f1 = false;
        for (int i = 1; i < n; i++) {
            int num = 0, cnt = 0;
            for (int j = 1; j <= a[i][0]; j++) {
                if (!vis[a[i][j]]) num = a[i][j];
                else b[++cnt] = a[i][j];
            }
            if (cnt == a[i][0] - 1 && cnt < pos) {
                for (int j = 1; j <= cnt; j++) c[b[j]] = 1;
                bool flag = true;
                for (int j = pos - cnt; j <= pos - 1; j++) {
                    if (!c[ans[j]]) {
                        flag = false;
                        break;
                    }
                }
                for (int j = 1; j <= cnt; j++) c[b[j]] = 0;
                if (flag) {
                    ans[pos] = num;
                    vis[num] = 1;
                    f1 = true;
                }
                else break;
            }
            if (f1) break;
        }
        if (!f1) return 0;
    }
    return 1;
    
}
int main() {
    int t; in >> t;
    while (t--) {
        in >> n;
        for (int i = 1; i < n; i++) {
            in >> a[i][0];
            for (int j = 1; j <= a[i][0]; j++) in >> a[i][j];
        }
        for (int i = 1; i <= n; i++) {
            if (check(i)) break;
        }
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    
    return 0;
}
