#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

struct rEAD {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_lEN = 1 << 18 | 1;
        static char buf[IN_lEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_lEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline rEAD & operator >> (_Tp&x) {
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

ll a[N];
ll b[N];
signed main() {
    int t; in >> t;
    while (t--) {
        ll n, l, k; in >> n >> l >> k;
        for (int i = 1; i <= n; i++) in >> a[i];
        sort(a + 1, a + n + 1);
        int l1 = 1, r = n;
        ll mx = 0, mn = 0;
        for (int i = 1; i <= l - k; i++) b[i] = a[l1++];
        for (int i = l - k + 1; i <= n; i += l) {
            for (int j = i; j <= min(n, i + k - 1); j++) b[j] = a[r--];
            for (int j = i + k; j <= min(n, i + l - 1); j++) b[j] = a[l1++];
            if (i + l - 1 <= n) {
                mx += 1ll * (l - k) * b[i + k - 1];
            }
            else if (i + k - 1 < n) {
                mx += 1ll * (n - (i + k - 1)) * b[i + k - 1];
            }
            for (int j = i; j <= min(n, i + k - 1); j++) if (j >= l) mx += b[j];
        }
        reverse(a + 1, a + n + 1);
        l1 = 1, r = n;
        k = l - k + 1;
        for (int i = 1; i <= n; i++) b[i] = 0;
        for (int i = 1; i <= l - k; i++) b[i] = a[l1++];
        for (int i = l - k + 1; i <= n; i += l) {
            for (int j = i; j <= min(n, i + k - 1); j++) b[j] = a[r--];
            for (int j = i + k; j <= min(n, i + l - 1); j++) b[j] = a[l1++];
            if (i + l - 1 <= n) {
                mn += 1ll * (l - k) * b[i + k - 1];
            }
            else if (i + k - 1 < n) {
                mn += 1ll * (n - (i + k - 1)) * b[i + k - 1];
            }
            for (int j = i; j <= min(n, i + k - 1); j++) if (j >= l) mn += b[j];
        }
        printf("%lld %lld\n", mx, mn);
    }
    return 0;
}
