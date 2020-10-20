#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e6 + 50;

namespace Min25 {

    int prime[N], id1[N], id2[N], flag[N], ncnt, m;

    ll g[N], sum[N], a[N], T, n;

    inline int ID(ll x) {
        return x <= T ? id1[x] : id2[n / x];
    }

    inline ll calc(ll x) {
        return x * (x + 1) / 2 - 1;
    }

    inline ll f(ll x) {
        return x;
    }

    inline void init() {
        T = sqrt(n + 0.5);
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (ll l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++) 
            for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++) 
                g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
    }

    inline ll solve(ll x) {
        if (x <= 1) return x;

        return n = x, g[ID(x)];
    }

}
ll qpow(ll a, ll b, ll k) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % k;
        a = a * a % k;
        b >>= 1;
    }
    return ans;
}
int main() {
    int t; in >> t;
    while (t--) {
        ll n, k;
        in >> n >> k;
        ll sum = Min25::solve(n + 1) - 2;
        //printf("%lld\n", sum);
        ll y = qpow(2, k - 2, k); 
        //printf("%lld %lld\n",sum,(3+n+1)%k*((n-1+k)%k)%k*y%k);
        sum %= k;
        //sum %= k;
        sum+=((3+n+1)%k*((n-1+k)%k))%k*y%k;
        sum %= k;
        printf("%lld\n",sum);
        //printf("%lld\n",sum);
    }
    return 0;
}
