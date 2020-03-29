#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const ll inv2 = qpow(2, mod - 2);

void fwt_and(ll a[], int len, int op) {
    for (int h = 2; h <= len; h <<= 1) {
        for (int j = 0; j < len; j += h) {
            for (int k = j; k < j + h / 2; k++) {
                a[k + h / 2] += a[k] * op;
            }
        }
    }
}

void fwt_or(ll a[], int len, int op) {
    for (int h = 2; h <= len; h <<= 1) {
        for (int j = 0; j < len; j += h) {
            for (int k = j; k < j + h / 2; k++) {
                a[k] += a[k + h / 2] * op;
            }
        }
    }
}

void fwt_xor(ll a[], int len, int op) {
    for (int h = 2; h <= len; h <<= 1) {
        for (int j = 0; j < len; j += h) {
            for (int k = j; k < j + h / 2; k++) {
                ll u = a[k], t = a[k + h / 2];
                a[k] = (u + t) % mod;
                a[k + h / 2] = (u - t + mod) % mod;
                if (op == -1) {
                    a[k] = a[k] * inv2 % mod;
                    a[k + h / 2] = a[k + h / 2] * inv2 % mod;
                }
            }
        }
    }
}
const int N = 2e5 + 50;
int notprime[N], prime[N];

ll a[N];
int main() {
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (!notprime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] < N; j++) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int len = 1;
        while (len <= m) len <<= 1;
        for (int i = 0; i < len; i++) a[i] = 0;
        for (int i = 1; i <= cnt && prime[i] <= m; i++) {
            a[prime[i]] = 1;
        }
        fwt_xor(a, len, 1);
        for (int i = 0; i < len; i++) {
            a[i] = qpow(a[i], n);
        }
        fwt_xor(a, len, -1);
        printf("%lld\n", a[0]);
    }
    return 0;
}