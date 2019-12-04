#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int x = b - a + c;
        if (x < 0) x = 0;
        else x = x / 2 + 1;
        int ans = 0;
        if (a > b) ans = 1;
        ans = max(ans, c - x + 1);
        printf("%d\n", ans);
    }
    return 0;
}