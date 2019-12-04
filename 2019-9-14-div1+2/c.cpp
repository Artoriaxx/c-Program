#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N];
int ans[N];
int l1[N], l2[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%1d", &a[i]);
        }
        bool flag = false;
        int now1, now2;
        now1 = now2 = 0;
        for (int k = 0; k <= 9; k++) {
            if (flag) break;
            flag = true;
            now1 = now2 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] < k) {
                    ans[i] = 1;
                    if (now1 > a[i]) {
                        flag = false;
                        break;
                    }
                    now1 = a[i];
                }
                else if (a[i] > k) {
                    ans[i] = 2;
                    if (now2 > a[i]) {
                        flag = false;
                        break;
                    }
                    now2 = a[i];
                }
                else {
                    if (a[i] >= now2) {
                        ans[i] = 2;
                        now2 = a[i];
                    }
                    else {
                        if (now1 > a[i]) {
                            flag = false;
                            break;
                        }
                        ans[i] = 1;
                        now1 = a[i];
                    }
                }
            }
        }
        if (!flag) puts("-");
        else {
            for (int i = 1; i <= n; i++) {
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}