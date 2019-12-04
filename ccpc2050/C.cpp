#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, m, k, a, b, c;
        scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &k, &a, &b, &c);
        long long res = inf;
        for (long long i = 0; i <= k; i++) {
            long long ans = 0;
            long long man = n + k - i;
            long long woman = m + k - i;
            ans += i * c;
            long long tmp = inf;
            for (long long j = 0; j <= man / 3; j++) {
                long long now = 0;
                now += j * b;
                now += (man - j * 3LL) % 2 == 0 ? (man - j * 3LL) / 2LL * a : ((man - j * 3LL + 1LL) / 2LL) * a;
                tmp = min(now, tmp);
            }
            tmp = min(tmp, (man / 3LL + 1LL) * b);
            ans += tmp;
            tmp = inf;
            for (long long j = 0; j <= woman / 3; j++) {
                long long now = 0;
                now += j * b;
                now += (woman - j * 3LL) % 2 == 0 ? (woman - j * 3LL) / 2LL * a : ((woman - j * 3LL + 1LL) / 2LL) * a;
                tmp = min(now, tmp);
            }
            tmp = min(tmp, (woman / 3LL + 1LL) * b);
            ans += tmp;
            res = min(ans, res);
        }
        cout << res << endl;
    }
    return 0;
}