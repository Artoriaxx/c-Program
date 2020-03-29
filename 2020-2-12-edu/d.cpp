#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
ll a[N];
ll num[100];
ll tmp[100];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(num, 0, sizeof(num));
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll sum = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        if (sum < n) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= m; i++) { 
            int cnt = 0;
            ll tmp = a[i];
            while (tmp > 1) {
                tmp /= 2;
                cnt++;
            }
            num[cnt]++;
        }
        int cnt = 0;
        int tot = 0;
        while (n) {
            if (n & 1) {
                num[cnt]--;
            }
            n >>= 1;
            cnt++;
        }
        int pos = 0;
        for (int i = 0; i <= 64; i++) {
            tmp[i] = num[i];
        }
        ll ans = 0;
        int l = -1, r = 0;
        for (int i = 0; i <= 64; i++) {
            if (tmp[i] == -1) {
                if (l == -1) {
                    l = i;
                }
                r = i;
                if (tmp[i + 1] > 0) {
                    tmp[i + 1] -= 1;
                    ans += r - l + 1;
                    l = -1;
                }
                else tmp[i + 1] = -1;
            }
            else if (tmp[i] >= 2) {
                tmp[i] -= 2;
                tmp[i + 1] += 1;
                while (tmp[i] >= 2) {
                    tmp[i] -= 2;
                    tmp[i + 1] += 1;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}