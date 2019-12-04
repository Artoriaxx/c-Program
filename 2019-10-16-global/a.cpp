#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int vis[N];
int main() {
    //printf("%d", 5 / 2);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) vis[i] = 1;
        a[i] /= 2;
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (sum == 0) break;
        if (vis[i]) continue;
        if (sum > 0) {
            if (a[i] >= 0) {
                continue;
            }
            else {
                a[i]--;
                sum--;
            }
        }
        if (sum < 0) {
            if (a[i] <= 0) continue;
            else {
                a[i]++;
                sum++;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d\n", a[i]);
    return 0;
}