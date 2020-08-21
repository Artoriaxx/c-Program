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

const int N = 3e5 + 50;
int d[N];
struct node {
    ll l, r;
} f[N][2];
int main() {
    int t; in >> t;
    while (t--) {
        ll n, k, l;
        in >> n >> k >> l;
        for (int i = 1; i <= n; i++) in >> d[i];
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (d[i] > l) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            puts("No");
            continue;
        }
        f[1][0].l = 0;
        f[1][0].r = l - d[1];
        f[1][0].r = min(f[1][0].r, k);
        f[1][1].r = 2 * k;
        f[1][1].l = 2 * k - l + d[1];
        f[1][1].l = max(f[1][1].l, k);
        bool flag1 = true, flag2 = true;
        for (int i = 2; i <= n; i++) {
            f[i][0].l = 0;
            f[i][0].r = l - d[i];
            f[i][0].r = min(f[i][0].r, k);
            f[i][1].r = 2 * k;
            f[i][1].l = 2 * k - l + d[i];
            f[i][1].l = max(f[i][1].l, k);
            f[i - 1][0].l++;
            f[i - 1][0].r++;
            f[i - 1][1].l++;
            f[i - 1][1].r++;
            if (f[i - 1][1].l > 2 * k) {
                f[i - 1][1].l -= 2 * k;
                f[i - 1][1].r -= 2 * k;
                swap(f[i - 1][0], f[i - 1][1]);
            }
            ll tmp0l = max(f[i][0].l, f[i - 1][0].l);
            ll tmp0r = min(f[i][0].r, f[i - 1][0].r);
            bool nowf = false;
            if (tmp0r >= tmp0l) f[i][0].l = tmp0l, nowf = true;
            ll tmp1l = max(f[i][1].l, f[i - 1][1].l);
            ll tmp1r = min(f[i][1].r, f[i - 1][1].r);
            if (tmp1r >= tmp1l) {
                f[i][1].l = tmp1l;
                nowf = true;
            }
            if (nowf) {
                if (l - d[i] >= k) {
                    f[i][0].l = 0;
                    f[i][0].r = k;
                    f[i][1].l = k;
                    f[i][1].r = 2 * k;
                }
                else {
                    if (tmp0r < tmp0l) flag1 = false;
                    if (tmp1r < tmp1l) flag2 = false;
                }
            }
            else {
                flag1 = false;
                flag2 = false;
            }
        }
        if (flag1 == false && flag2 == false) puts("No");
        else if (f[n][0].r >= f[n][0].l || f[n][1].r >= f[n][1].l) puts("Yes");
        else puts("No");
    }
    return 0;
}
