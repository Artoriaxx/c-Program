#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int c, m, x;
        scanf("%d%d%d", &c, &m, &x);
        int minn = min(c, m);
        minn = min(minn, x);
        int ans = minn;
        c -= minn; m -= minn; x -= minn;
        if (c == 0 || m == 0) {
            printf("%d\n", ans);
        }
        else {
            if (c > m) swap(c, m);
            ans += min(c, m - c);
            c -= (m - c);
            if (c > 0) {
                ans += 2 * c / 3;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}