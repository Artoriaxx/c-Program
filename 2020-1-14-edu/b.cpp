#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll num1 = a;
        ll num2 = 0;
        ll now = 9;
        while (now <= b) {
            now *= 10;
            now += 9;
            num2++;
        }
        printf("%lld\n", num1 * num2);
    }
    return 0;
}