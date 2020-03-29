#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int a[N];
ll pre[N];
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        int n, p;
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        ll mn = 1e18;
        for (int i = p; i <= n; i++) {
            if ((ll)p * a[i] - pre[i] + pre[i - p] < mn) mn = (ll)p * a[i] - pre[i] + pre[i - p];
        }
        printf("Case #%d: %d\n", ++cse, mn);
    }
    return 0;
}