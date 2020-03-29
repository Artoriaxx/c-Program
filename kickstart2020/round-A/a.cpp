#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        int n, b;
        scanf("%d%d", &n, &b);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (b >= a[i]) {
                b -= a[i];
                ans++;
            }
        }

        printf("Case #%d: %d\n", ++cse, ans);
    }
    return 0;
}