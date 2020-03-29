#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 2 * n + 1);
        printf("%d\n", a[n + 1] - a[n]);
    }
    return 0;
}