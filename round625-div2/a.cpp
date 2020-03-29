#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int r[N], b[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (r[i] == 1 && b[i] == 0) x++;
        else if (r[i] == 0 && b[i] == 1) y++;
    }
    if (x == 0) {
        puts("-1");
        return 0;
    }
    int ans = 1;
    if (x <= y) {
        int tmp = y + 1 - x;
        ans += tmp / x;
        if (tmp % x != 0) ans++;
    } 
    printf("%d\n", ans);

    return 0;
}