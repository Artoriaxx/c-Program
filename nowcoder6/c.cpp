#include <bits/stdc++.h>
#define pii pair<int, int>
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
int sum[N][N];
pii q[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, m; in >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                in >> a[i][j];
            }
        }
        double ans = 0;
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                sum[j][i] = sum[j][i - 1] + a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            int nowx = 0, nowy = 0;
            for (int j = 1; j <= m; j++) {
                int tmpx = sum[j][i];
                int tmpy = a[i][j];
                if (nowx == 0 && nowy == 0) {
                    nowx = tmpx;
                    nowy = tmpy;
                }
                else {
                    if (1ll * (nowx + tmpx) * tmpy > 1ll * (nowy + tmpy) * tmpx) {
                        if (1ll * (nowx + tmpx) * nowy > 1ll * (nowy + tmpy) * nowx) {
                            nowx = nowx + tmpx;
                            nowy = nowy + tmpy;
                        }
                    }
                    else {
                        if (1ll * tmpx * nowy > 1ll * tmpy * nowx) {
                            nowx = tmpx;
                            nowy = tmpy;
                        }
                    }
                }
            }
            ans = max(ans, 1.0 * nowx / nowy);
        }
        
        printf("%.8f\n", ans);
    }
    return 0;
}
