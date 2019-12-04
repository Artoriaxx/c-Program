#include <bits/stdc++.h>
#define N 300005
using namespace std;
long long a[N];
int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    int l = 1, r = n;
    while (a[l] == 0) {
        l++;
    }
    while (r > l) {
        if (a[r] == 1 || a[r] == 0) {
            r--;
            continue;
        }
        else {
            if (a[l] > 0) {
                if (a[r] / 2 <= a[l]) {
                    if (a[r] % 2 == 0) {
                        a[l] -= a[r] / 2;
                        ans += a[r] / 2;
                        if (a[l] == 0) l++;
                        a[r] = 0;
                        r--;
                    }
                    else {
                        a[l] -= (a[r] / 2 - 1);
                        ans += a[r] / 2;
                        if (a[l] == 0) l++;
                        a[r] = 0;
                        r--;
                    }
                }
                else { 
                    a[r] -= a[l] * 2;
                    ans += a[l];
                    a[l] = 0;
                    if (a[r] == 1) {
                        a[r] = 0;
                        a[l]++;
                    }
                    else l++;
                    if (a[r] == 0) r--;
                    
                }
            }
            else {
                l++;
                continue;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += a[i] / 3;
    }
    cout << ans << endl;
    return 0;
}