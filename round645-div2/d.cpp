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

const int N = 4e5 + 50;
ll a[N];
ll pre[N];
ll sump[N];
int main() {
    int n; ll x;
    in >> n >> x;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    n *= 2;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        ll x = (1 + a[i]) * a[i] / 2;
        sump[i] = sump[i - 1] + x;
    }
    ll ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        ll y = x - a[i];
        if (y <= 0) {
            ans = max(ans, (a[i] + a[i] - x + 1) * x / 2);
            continue;
        }
        int l = i + 1, r = n;
        int p = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] - pre[i] <= y) {
                p = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ll z = x - pre[p] + pre[i];
        ll now = sump[p] - sump[i];
        if (z <= a[p + 1]) {
            now += (1 + z) * z / 2;
        }
        else {
            now += (1 + a[p + 1]) * a[p + 1] / 2;
            z -= a[p + 1];
            now += (a[i] + a[i] - z + 1) * z / 2;
        }
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
