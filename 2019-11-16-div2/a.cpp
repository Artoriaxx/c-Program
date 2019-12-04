#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 60;
int a[N], b[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                if (!l) l = i, r = i;
                else r = i;
            }
        }
        bool flag = true;
        int val = b[l] - a[l];
        if (val < 0) flag = false;
        for (int i = l; i <= r; i++) {
            a[i] += val;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                flag = false;
                break;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}