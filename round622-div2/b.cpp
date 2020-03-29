#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);

        int ans2 = min(x - 1, n - y) + min(y - 1, n - x);
        if (x - 1 - min(x - 1, n - y) > 0 && y - 1 - min(y - 1, n - x) > 0) {
            ans2 += min(x - 1 - min(x - 1, n - y), y - 1 - min(y - 1, n - x));
        }
        ans2++;
        if (x > y) {
            swap(x, y);
        }
        int ans1 = 0;
        ans1 = min(x - 1, n - y - 1) + min(y - 1, n - x - 1);
        if (n - y - min(x - 1, n - y - 1) > 0 && n - x - min(y - 1, n - x - 1) > 0) {
            ans1 += min(n - y - min(x - 1, n - y - 1), n - x - min(y - 1, n - x - 1));
        }
        ans1 = n - ans1;
        ans1 = max(1, ans1);
        ans2 = max(1, ans2);
        ans2 = min(n, ans2);
        printf("%d %d\n", min(ans1, n), ans2);
    }
    return 0;
}