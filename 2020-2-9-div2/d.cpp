#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int x[N], y[N];
int a[N], b[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    if (n & 1) {
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int nxt = i + 1;
        if (nxt > n) nxt = 1;
        a[i] = x[nxt] - x[i];
        b[i] = y[nxt] - y[i];
        //printf("%d %d\n", a[i], b[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n / 2; i++) {
        if (a[i] != -a[i + n / 2]) {
            flag = false;
            break;
        }
        if (b[i] != -b[i + n / 2]) {
            flag = false;
            break;
        }
    }
    if (flag) puts("YES");
    else puts("NO");
    return 0;
}