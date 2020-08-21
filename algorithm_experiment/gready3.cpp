#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
struct node {
    int l, r;
    bool operator < (const node &b) const {
        return l == b.l ? r < b.r : l < b.l;
    }
} a[N];
int vis[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + m + 1);
    int tot = 0;
    int ans = 0;
    while (tot < m) {
        int pos = 0;
        ans++;
        for (int i = 1; i <= m; i++) {
            if (vis[i]) continue;
            if (a[i].l > pos) pos = a[i].r, tot++, vis[i] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
