#include <bits/stdc++.h>
using namespace std;
struct node {
    int t, l, h;
    bool operator < (const node &b) const {
        return t < b.t;
    }
} a[150];
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].h);
        }
        sort(a + 1, a + n + 1);
        int l = m, r = m;
        int tmp = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int x = a[i].t - tmp;
            l -= x;
            r += x;
            if (l > a[i].h || r < a[i].l) {
                flag = false;
                break;
            }
            else {
                r = min(r, a[i].h);
                l = max(l, a[i].l);
                tmp = a[i].t;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}