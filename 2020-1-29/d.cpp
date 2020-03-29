//不加inline TLE >5000ms 加inline 1994ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 985661441;
const int N = 3e5 + 50;
namespace comb {
    const int N = 2e5 + 50;
    ll fac[N] = {1, 1}, inv[N] = {1, 1}, f[N] = {1, 1};
    void init() {
        for (int i = 2; i < N; i++) {
            fac[i] = fac[i - 1] * i % mod;
            f[i] = (mod - mod / i) * f[mod % i] % mod;//线性递推逆元
            inv[i] = inv[i - 1] * f[i] % mod;//阶乘的逆元
        }
    }
    inline ll C(int a, int b) {
        if (b > a || b < 0) return 0;
        return fac[a] * inv[b] % mod * inv[a - b] % mod;
    }
};

inline ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

namespace ntt {
    ll w[N];
    int G = 3;
    inline void ntt(ll a[], int n, int op) {//ntt
        for (int i = 0, j = 0; i < n; i++) {
            if (i > j) swap(a[i], a[j]);
            for (int l = n >> 1; (j ^= l) < l; l >>= 1);
        }
        for (int i = 2; i <= n; i <<= 1) {
            for (int j = 0, m = i >> 1; j < n; j += i) {
                for (int k = 0; k < m; k++) {
                    ll b = w[n / i * k] * a[j + m + k] % mod;
                    a[j + m + k] = (a[j + k] - b + mod) % mod;
                    a[j + k] = (a[j + k] + b) % mod;
                }
            }
        }
        if (op == -1) {
            reverse(a + 1, a + n);
            ll invN = qpow(n, mod - 2);
            for (int i = 0; i < n; i++) a[i] = a[i] * invN % mod;
        }
    }
    void getroot() {//求原根
        static int prime[1000], cnt;
        int n = mod - 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prime[cnt++] = i;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) prime[cnt++] = n;
        for (int i = 1; i < mod; i++) {
            if (qpow(i, mod - 1) == 1) {
                bool flag = true;
                for (int j = 0; j < cnt; j++) {
                    if (qpow(i, (mod - 1) / prime[j]) == 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    G = i;
                    break;
                }
            }
        }
    }
    inline void conv(int n, ll x[], ll y[]) {//卷积
        ll g = qpow(G, (mod - 1) / n);
        w[0] = 1;
        for (int i = 1; i < n; i++) w[i] = w[i - 1] * g % mod;
        ntt(x, n, 1); ntt(y, n, 1);
        for (int i = 0; i < n; i++) x[i] = x[i] * y[i] % mod;
        ntt(x, n, -1);
    }
};
ll p[20], e[20];
ll g[N];
ll x[N], y[N];
ll f[N];
int main() {
    comb::init();
    int cse = 0;
    int m, k;
    while (~scanf("%d%d", &m, &k)) {
        ll w = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%lld%lld", &p[i], &e[i]);
            w += e[i];
        }
        for (int i = 0; i <= w; i++) g[i] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= w; j++) {
                g[j] = g[j] * comb::C(e[i] + j - 1, j - 1) % mod;//挡板法
            }
        }
        int n = 1;
        while (n < w + 1) n <<= 1;
        n <<= 1;
        for (int i = 0; i < n; i++) x[i] = 0, y[i] = 0;
        for (int i = 0; i <= w; i++) {
            x[i] = comb::inv[i];
            if (i & 1) x[i] = -x[i];
            y[i] = g[i] * comb::inv[i] % mod;
        }
        ntt::conv(n, x, y);
        for (int i = 0; i < n; i++) f[i] = 0;
        for (int i = 1; i <= w; i++) {
            f[i] = x[i] * comb::fac[i] % mod;
        }
        printf("Case #%d:", ++cse);
        for (int i = 1; i <= k; i++) {
            ll tot = 0;
            for (int j = 1; j <= w; j++) {//循环还是从1到w，但是由于f[w+1]为0，所以除了i=1的时候，都取不到f[w]
                tot = (tot + qpow(f[j + 1], i - 1) * qpow(f[j], k - i + 1) % mod) % mod;
            }
            printf(" %lld", tot);
        }
        puts("");
    }
    return 0;
}