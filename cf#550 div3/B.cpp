#include <bits/stdc++.h>
#define N 2005
using namespace std;
int a[N];
int main() {
    int n;
    scanf("%d", &n);
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1) odd++;
    }
    int even = n - odd;
    if (abs(odd - even) <= 1) {
        cout << "0" << endl;
    }
    else {
        sort (a + 1, a + n + 1);
        bool flag = false;
        if (even - odd > 0) {
            flag = true;
        }
        int rem = abs(even - odd);
        rem--;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (flag) {
                if (a[i] % 2 == 0) {
                    rem--;
                    ans += a[i];
                    if (rem == 0) break;
                }
            }
            else {
                if (a[i] % 2 == 1) {
                    rem--;
                    ans += a[i];
                    if (rem == 0) break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;

}