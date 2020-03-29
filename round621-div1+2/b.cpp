#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int maxx = 0;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            maxx = max(maxx,  a[i]);
            if (a[i] == x) {
                flag = true;
                break;
            } 
        }
        if (flag) puts("1");
        else {
            int ans = 2;
            x -= 2 * maxx;
            if (x > 0) {
                ans += x / maxx;
                if (x % maxx != 0) ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}