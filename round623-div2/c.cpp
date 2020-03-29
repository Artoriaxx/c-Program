#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int b[N];
int a[N];
int vis[N];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        bool flag = true;
        bool f2 = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            if (b[i] == 2 * n) {
                flag = false;
            }
            if (b[i] == 1) {
                f2 = true;
            }
            vis[b[i]] = 1;
        }
        if (!flag || !f2) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            a[2 * i - 1] = b[i];
        }
        flag = true;
        for (int i = 1; i <= n; i++) {
            f2 = false;
            for (int j = a[2 * i - 1] + 1; j <= 2 * n; j++) {
                if (!vis[j]) {
                    vis[j] = 1;
                    a[2 * i] = j;
                    f2 = true;
                    break;
                }
            }
            if (!f2) flag = false;
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= 2 * n; i++) {
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}