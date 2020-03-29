#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll inv2 = (mod + 1) >> 1;

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

const ll N = 1 << 22;
ll a[N], b[N];
int bit[N];
ll A[21][N], B[21][N];
ll C[21][N];
int main() {
    int m;
    scanf("%d", &m);
    int n = (1 << m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        bit[i] = 0;
        int x = i;
        while (x) {
            if (x & 1) bit[i]++;
            x >>= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        A[bit[i]][i] = a[i] * (1ll << bit[i]) % mod;
        B[bit[i]][i] = b[i];
    }
    for (int i = 0; i < m; i++) {
        fwt_xor(A[i], n, 1);
        fwt_xor(B[i], n, 1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < n; k++) {
                C[i - j][k] = (C[i - j][k] + A[j][k] * B[i][k] % mod) % mod;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        fwt_xor(C[i], n, -1);
    }
    ll now = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + C[bit[i]][i] * now % mod) % mod;
        now = now * 1526ll % mod;
    }
    printf("%lld\n", ans);
    return 0;
}