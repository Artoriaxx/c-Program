#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[60];
void fibo(int n) {
    if (n == 1 || n == 2) {
        f[n] = 1; return;
    }
    if (f[n]) return;
    else {
        fibo(n - 1);
        fibo(n - 2);
        f[n] = f[n - 1] + f[n - 2];
    }
}
int main() {
    fibo(50);
    for (int i = 1; i <= 50; i++) {
        printf("%lld\n", f[i]);
    }
    return 0;
}