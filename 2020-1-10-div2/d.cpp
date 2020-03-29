#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
ll a[N];
ll b[N];
ll pow2[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) b[i] = a[i];
    pow2[0] = 1;
    for (int i = 1; i <= 31; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    sort (a + 1, a + n + 1);
    ll tmp = a[n];
    int cnt = 0;
    while (tmp) {
        tmp >>= 1;
        cnt++;
    }
    ll ans = 0;
    for (int i = cnt - 1; i >= 0; i--) {
        ll maxx = 0;
        int x = 0;
        for (int j = 1; j <= n; j++) {
            maxx = max(maxx, a[j]);
        }
        x = 1;
        for (int j = 1; j <= n; j++) {
            if (((a[j] >> i) % 2) == 1) {
                if (x == 1) {
                    a[j] -= pow2[i];
                }
            }
            else {
                if (x == 1) {
                    a[j] += pow2[i];
                }
            }
        }
        ll maxy = 0;
        for (int j = 1; j <= n; j++) {
            maxy = max(maxy, a[j]);
        }
        for (int j = 1; j <= n; j++) {
            if (((a[j] >> i) % 2) == 1) {
                if (x == 1) {
                    a[j] += pow2[i];
                }
            }
            else {
                if (x == 1) {
                    a[j] -= pow2[i];
                }
            }
        }
        if (maxx < maxy) {
            
        }
        else {
            ans += x << i;
            for (int j = 1; j <= n; j++) {
                if (((a[j] >> i) % 2) == 1) {
                    if (x == 1) {
                        a[j] -= pow2[i];
                    }
                }
                else {
                    if (x == 1) {
                        a[j] += pow2[i];
                    }
                }
            }
        }
    }
    
    ll tans = 0;
    for (int i = 1; i <= n; i++) {
        tans = max(tans, (ll)b[i] ^ ans);
    }
    printf("%lld\n", tans);
    return 0;
}