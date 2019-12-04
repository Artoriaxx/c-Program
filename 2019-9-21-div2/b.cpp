#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
    if (n == 1) {
        if (a[1] == 0) {
            puts("0");
        }
        else {
            if (k >= 1) {
                puts("0");
            }
            else printf("%d", a[1]);
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!k) break;
        if (i == 1) {
            if (a[i] != 1 && k) {
                a[i] = 1;
                k--;
            }
        }
        else {
            if (a[i] != 0 && k) {
                a[i] = 0;
                k--;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    return 0;
}