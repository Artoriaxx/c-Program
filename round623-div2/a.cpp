#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        int maxx = x  * b;
        maxx = max(maxx, y * a);
        maxx = max(maxx, (b - y - 1) * a);
        maxx = max(maxx, (a - x - 1) * b);
        printf("%d\n", maxx);
    }
    return 0;
}