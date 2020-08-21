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
ll a[N];
ll b[N];
ll c[N];
int main() {
    int n, d, m; in >> n >> d >> m;
    for (int i = 1; i <= n; i++) in >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ll n1 = 0, n2 = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= m) b[++n1] = a[i], ans += a[i];
        else c[++n2] = a[i];
    }
    for (int i = 1; i <= n1; i++) b[i] += b[i - 1];
    for (int i = 1; i <= n2; i++) c[i] += c[i - 1];
    for (ll i = 1; i <= n2; i++) {
        ll x = 1ll * (i - 1) * d;
        ll now = c[i];
        if (x + i <= n2) now += b[n1];
        else if (n1 - (x + i - n2) < 0) continue;
        else now += b[n1 - (x + i - n2)];
        ans = max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}
