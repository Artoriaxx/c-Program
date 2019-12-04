#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
int a[N];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, s, p;
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y > s) y--;
        a[i] = n - x + 1 + abs(s - y) + 1;
    }
    sort(a + 1, a + p + 1, cmp);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        ans = max(ans, a[i] + i - 1);
    }
    cout << ans;
    return 0;
}