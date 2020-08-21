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

const int N = 5050;
int Lcm[N][N];
int q[N];
int mn[N][N];
int main() {
    int n, m, k;
    in >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!Lcm[i][j]) {
                for (int k = 1; k * i <= n && k * j <= m; k++) {
                    Lcm[k * i][k * j] = i * j * k;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = 0;
        for (int j = 1; j <= m; j++) {
            while (l <= r && j - q[l] >= k) l++;
            while (l <= r && Lcm[i][j] >= Lcm[i][q[r]]) r--;
            q[++r] = j;
            if (j >= k) mn[i][j] = Lcm[i][q[l]];
        }
    }
    ll ans = 0;
    for (int i = k; i <= m; i++) {
        int l = 1, r = 0;
        for (int j = 1; j <= n; j++) {
            while (l <= r && j - q[l] >= k) l++;
            while (l <= r && mn[j][i] >= mn[q[r]][i]) r--;
            q[++r] = j;
            if (j >= k) ans += mn[q[l]][i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
