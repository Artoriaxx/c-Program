#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int pos[40];
int sze[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int now = a[i];
        int cnt = 0;
        while (now) {
            pos[cnt++] += now & 1;
            now /= 2;
        }
        sze[i] = cnt;
    }
    // for (int i = 0; i <= 4; i++) {
    //     printf("%d\n", pos[i]);
    // }
    int maxx = -1;
    int p;
    for (int i = 1; i <= n; i++) {
        int now = 0;
        for (int j = 0; j < sze[i]; j++) {
            if (((a[i] >> j) & 1) && pos[j] == 1) {
                now += 1 << j;
            }
        }
        if (now > maxx) {
            maxx = now;
            p = i;
        }
    }
    printf("%d", a[p]);
    for (int i = 1; i <= n; i++) {
        if (i == p) continue;
        printf(" %d", a[i]);
    }
    return 0;
}