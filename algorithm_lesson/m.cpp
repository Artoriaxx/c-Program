#include <bits/stdc++.h>
#define re register
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
const int N = 1e4 + 50;
int d[505][5505];
int a[5505][505];
int h[N];
inline int max(int x, int y) {
    return x > y ? x : y;
}
inline int query(int x, int y) {
    int ans = 0;
    for (re int i = y; i; i -= i & -i) if (d[x][i] > ans) ans = d[x][i];
    for (re int i = x; i; i -= i & -i) if (a[y][i] > ans) ans = a[y][i];
    return ans;
}
int k, r;
inline void update(int x, int y, int v) {
    for (re int i = y; i < r; i += i & -i) if (v > d[x][i]) d[x][i] = v;
    for (re int i = x; i < k + 2; i += i & -i) if (v > a[y][i]) a[y][i] = v;
}
int main() {
    int n;
    in >> n >> k;
    for (re int i = 1; i <= n; i++) {
        in >> h[i];
        if (h[i] > r) r = h[i];
    }
    r += k + 1;
    int ans = 0;
    for (re int i = 1; i <= n; i++) {
        for (re int j = k; j >= 0; j--) {
            int val = query(j + 1, h[i] + j) + 1;
            if (val > ans) ans = val;
            update(j + 1, h[i] + j, val);
        }
    }
    printf("%d\n", ans);
    return 0;
}
