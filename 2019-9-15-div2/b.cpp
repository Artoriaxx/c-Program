#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 60;
typedef long long ll;
int a[N];
ll f[N][2];
int main() {
    int n;
    scanf("%d", &n);
    ll pos = 0, neg = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = f[i - 1][1];
        }
        else {
            f[i][1] = f[i - 1][0] + 1;
            f[i][0] = f[i - 1][1];
        }
        neg += f[i][1];
        pos += f[i][0];
    }
    printf("%lld %lld\n", neg, pos);
    return 0;
}