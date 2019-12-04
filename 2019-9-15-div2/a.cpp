#include <bits/stdc++.h>
using namespace std;
int main() {
    int a1, a2, k1, k2, n;
    scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
    int x = n;
    for (int i = 1; i <= a1; i++) {
        x -= (k1 - 1);
    }
    for (int i = 1; i <= a2; i++) {
        x -= (k2 - 1);
    }
    x = max(0, x);
    x = min(a1 + a2, x);
    printf("%d ", x);
    x = n;
    if (k1 <= k2) {
        int cnt = 0;
        for (int i = 1; i <= a1; i++) {
            x -= k1;
            if (x < 0) break;
            cnt++;
        }
        if (x > 0) {
            for (int i = 1; i <= a2; i++) {
                x -= k2;
                if (x < 0) break;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    else {
        int cnt = 0;
        for (int i = 1; i <= a2; i++) {
            x -= k2;
            if (x < 0) break;
            cnt++;
        }
        if (x > 0) {
            for (int i = 1; i <= a1; i++) {
                x -= k1;
                if (x < 0) break;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}