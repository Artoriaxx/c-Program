#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int notprime[N], prime[N], mu[N];
int pre[N];
int k;
ll calc(int n, int m) {
    n /= k; m /= k;
    ll ans = 0;
    int x = min(n, m);
    int t;
    for (int i = 1; i <= x; i = t + 1) {
        t = min(n / (n / i), m / (m / i));
        ans += (ll)(pre[t] - pre[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}
ll F[N];
ll f[N];
int main() {
    mu[1] = 1;
    int cnt = 0;
    for (int i = 2; i <= N - 5; i++) {
        if (!notprime[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= N - 5; j++) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            else mu[i * prime[j]] = -mu[i];
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    int x = min(n, m);
    for (int i = 1; i <= x; i++) {
        F[i] = (ll)(n / i) * (ll)(m / i);
    }
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= x; j += i) {
            f[i] += (ll)mu[j / i] * F[j];
        }
    }
    for (int i = 1; i <= x; i++) {
        ans += f[i] * (ll)i;
    }
    printf("%lld\n", 2LL * ans - (ll)n * (ll)m);
    return 0;
}