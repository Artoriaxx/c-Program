#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a[1], &a[2], &a[3]);
        sort (a + 1, a + 3 + 1);
        int x = a[3] - a[2];
        int ans = 0;
        if (x >= a[1]) {
            ans += a[1];
            a[1] = 0;
            a[3] -= a[1];
            ans += a[2];
        }
        else {
            a[3] = a[2];
            a[1] -= x;
            ans += x;
            int y = a[1] % 2;
            a[1] /= 2;
            a[2] -= a[1];
            a[3] -= a[1];
            ans += a[1] * 2;
            a[2] -= y;
            ans += y;
            ans += a[2];
        }
        printf("%d\n", ans);
    }
    return 0;
}