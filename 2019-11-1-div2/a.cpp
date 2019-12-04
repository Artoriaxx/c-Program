#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (gcd(a, b) != 1) {
            puts("Infinite");
        }
        else puts("Finite");
    }
    return 0;
}