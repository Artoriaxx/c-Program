#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 250;
int sx[N], sy[N];
int fx[N], fy[N];
char ans[N * N * 2];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &sx[i], &sy[i]);
    }
    for (int i = 1; i <= k; i++) scanf("%d%d", &fx[i], &fy[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (i & 1) ans[++cnt] = 'R';
            else ans[++cnt] = 'L';
        }
        if (i != n) ans[++cnt] = 'D';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (i & 1) ans[++cnt] = 'L';
            else ans[++cnt] = 'R';
        }
        if (i != n) ans[++cnt] = 'U';
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) putchar(ans[i]);
    return 0;
}