#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int a[N];
int b[N];
int check(int val, int n, int k) {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 1; i < n; i++) {
        if (b[i + 1] - b[i] <= val) {
            continue;
        }
        else {
            while (b[i + 1] - b[i] > val) {
                b[i] += val;
                k--;
            }
        }
    }
    return k >= 0;
}
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int l = 1, r = 1e9 + 50;
        int ans = 1e9 + 50;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, n, k)) {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else l = mid + 1;
        }
        printf("Case #%d: %d\n", ++cse, ans);
    }
    return 0;
}