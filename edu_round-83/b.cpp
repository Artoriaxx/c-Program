#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = n; i >= 1; i--) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}