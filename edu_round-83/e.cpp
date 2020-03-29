#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int a[N], g[N][N], f[N];
struct node {
    int l, r;
    bool operator < (const node &b) {
        return r < b.r;
    }
} p[N * N];
int main() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g[i][i] = a[i];
        p[++tot] = {i, i};
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                if (g[l][k] && g[k + 1][r] && g[l][k] == g[k + 1][r]) {
                    g[l][r] = g[l][k] + 1;
                    p[++tot] = {l, r};
                }
            }
        }
    }
    sort(p + 1, p + tot + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        while (p[j].r == i) {
            f[i] = min(f[i], f[p[j].l - 1] + 1);
            j++;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}