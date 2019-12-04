#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int cnt[N];
int rpos[N], lpos[N];
int vis[N];
int main() {
    int n;
    scanf("%d", &n);
    int ma = 0;
    int num;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] > ma) ma = cnt[a[i]], num = a[i];
    }
    printf("%d\n", n - cnt[num]);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == num && a[i - 1] != num) rpos[++cnt1] = i;
        if (a[i] == num && a[i + 1] != num) lpos[++cnt2] = i;
    }
    for (int i = rpos[1] - 1; i >= 1; i--) {
        if (a[i] < num) {
            printf("1 %d %d\n", i, i + 1);
        }
        else {
            printf("2 %d %d\n", i, i + 1);
        }
    }
    for (int i = 2; i <= cnt1; i++) {
        for (int j = rpos[i] - 1; j >= lpos[i - 1] + 1; j--) {
            if (a[j] < num) {
                printf("1 %d %d\n", j, j + 1);
            }
            else {
                printf("2 %d %d\n", j, j + 1);
            }
        }
    }
    for (int i = lpos[cnt2] + 1; i <= n; i++) {
        if (a[i] < num) {
            printf("1 %d %d\n", i, i - 1);
        }
        else {
            printf("2 %d %d\n", i, i - 1);
        }
    }
    return 0;
}