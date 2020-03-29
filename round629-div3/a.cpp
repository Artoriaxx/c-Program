#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a % b == 0) puts("0");
        else {
            int x = a / b;
            printf("%d\n", (x + 1) * b - a);
        }
    }
    return 0;
}