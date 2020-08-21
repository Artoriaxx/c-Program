#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 250;
int a[N];
int f[N][N];
int g[N][N];
int pre[N];
int ans1[N][N];
int ans2[N][N];
struct node {
    int l, r;
    node() {}
    node(int l, int r): l(l), r(r) {}
};
vector<int> tmp[N];
node q[N];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= 2 * n; i++) g[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= 2 * n - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                if (f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1] > f[l][r]) {
                    f[l][r] = f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1];
                    ans1[l][r] = k;
                }
                if (g[l][k] + g[k + 1][r] + pre[r] - pre[l - 1] < g[l][r]) {
                    g[l][r] = g[l][k] + g[k + 1][r] + pre[r] - pre[l - 1];
                    ans2[l][r] = k;
                }
            }
        }
    }
    int p1 = 1, p2 = 1;
    for (int i = 2; i <= n; i++) {
        if (f[i][i + n - 1] > f[p1][p1 + n - 1]) p1 = i;
        if (g[i][i + n - 1] < g[p2][p2 + n - 1]) p2 = i;
    }
    q[0] = node(p2, p2 + n - 1);
    int flag = -2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == flag || j == flag + 1) tmp[i].push_back(pre[q[j].l - 1] - pre[q[j].r]);
            else tmp[i].push_back(pre[q[j].r] - pre[q[j].l - 1]);
        }
        for (int j = 0; j < i; j++) {
            if (q[j].r - q[j].l != 0) {
                for (int k = i; k > j; k--) q[k] = q[k - 1];
                node x = q[j];
                q[j] = node(x.l, ans2[x.l][x.r]);
                q[j + 1] = node(ans2[x.l][x.r] + 1, x.r);
                flag = j;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < tmp[i].size(); j++) {
            printf("%d ", tmp[i][j]);
        }
        tmp[i].clear();
        puts("");
    }
    puts("");
    q[0] = node(p1, p1 + n - 1);
    flag = -2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == flag || j == flag + 1) tmp[i].push_back(pre[q[j].l - 1] - pre[q[j].r]);
            else tmp[i].push_back(pre[q[j].r] - pre[q[j].l - 1]);
        }
        for (int j = 0; j < i; j++) {
            if (q[j].r - q[j].l != 0) {
                for (int k = i; k > j; k--) q[k] = q[k - 1];
                node x = q[j];
                q[j] = node(x.l, ans1[x.l][x.r]);
                q[j + 1] = node(ans1[x.l][x.r] + 1, x.r);
                flag = j;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < tmp[i].size(); j++) {
            printf("%d ", tmp[i][j]);
        }
        tmp[i].clear();
        puts("");
    }
    return 0;
}
