#include <bits/stdc++.h>
#define N 300005
using namespace std;
int a[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[1]) {
            ans = i - 1;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] != a[n]) {
            ans = max(ans, n - i);
        }
    }
    cout << ans << endl;
    return 0;
}