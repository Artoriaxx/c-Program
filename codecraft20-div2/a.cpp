#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += a[i];
        if (sum > m) printf("%d\n", m);
        else printf("%d\n", sum);
    }
    return 0;
}