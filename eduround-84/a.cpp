#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        if (n < k * k) {
            puts("NO");
        }
        else {
            if (n % 2 == 0 && k % 2 == 1) puts("NO");
            else if (n % 2 == 1 && k % 2 == 0) puts("NO");
            else puts("YES");
        }

    }
    return 0;
}
