#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (a >= i && b >= 2 * i + j && c >= 2 * j) {
                    ans = max(ans, 3 * i + 3 * j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}