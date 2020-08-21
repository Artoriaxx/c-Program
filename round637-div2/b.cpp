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
int p[N], a[N], pre[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, k;
        in >> n >> k;
        for (int i = 1; i <= n; i++) p[i] = 0, pre[i] = 0;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 1; i <= n; i++) {
            if (i > 1 && i < n) {
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) p[i] = 1;
            }
        }
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + p[i];
        int ans1 = 1, ans2 = 0;
        for (int i = 1; i <= n - k + 1; i++) {
            int x = pre[i + k - 1] - pre[i - 1] - p[i] - p[i + k - 1];
            if (x > ans2) {
                ans1 = i;
                ans2 = x;
            }
        }
        printf("%d %d\n", ans2 + 1, ans1);
    }
    return 0;
}
