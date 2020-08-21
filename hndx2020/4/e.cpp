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
int m[N], r[N];
int vis[N];
int a[N];
int main() {
    int n; in >> n;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        in >> m[i] >> r[i];
        if (m[i] > r[i]) x++;
    }
    int i = 1;
    int ans = 0;
    int y = n - x;
    while (x <= y && i < n) {
        if (m[i] <= r[i]) {
            if (m[i + 1] <= r[i + 1]) {
                y--;
                ans++;
                a[ans] = i;
                i++;
            }
            else if (m[i + 1] + m[i] > r[i + 1] + r[i]) {
                y--;
                ans++;
                a[ans] = i;
                i++;
            }
        }
        else {
            if (m[i + 1] <= r[i + 1] && m[i + 1] + m[i] > r[i + 1] + r[i]) {
                y--;
                ans++;
                a[ans] = i;
                i++;
            }
        }
        i++;
    }
    if (x <= y) puts("-1");
    else {
        printf("%d\n", ans);
        for (int i = 1; i <= ans; i++) printf("%d %d\n", a[i], a[i] + 1);
    }
    return 0;
}
