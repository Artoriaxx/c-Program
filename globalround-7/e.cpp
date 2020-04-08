#include <bits/stdc++.h>
#define lson (o << 1)
#define rson (o << 1 | 1)
using namespace std;
typedef long long ll;
const int N = 3e5 + 50;
int p[N], q[N];
int pos[N];
int maxv[N << 2];
int addv[N << 2];
void pushup(int o) {
    maxv[o] = max(maxv[lson], maxv[rson]);
}
void pushdown(int o) {
    if (addv[o]) {
        addv[lson] += addv[o]; addv[rson] += addv[o];
        maxv[lson] += addv[o]; maxv[rson] += addv[o];
        addv[o] = 0; 
    }
}
void update(int o, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    pushdown(o);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(lson, l, mid, ql, qr, v);
    if (qr > mid) update(rson, mid + 1, r, ql, qr, v);
    pushup(o);
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]), pos[p[i]] = i;
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    int ans = n; printf("%d", n);
    update(1, 1, n, 1, pos[ans], 1);
    for (int i = 1; i < n; i++) {
        update(1, 1, n, 1, q[i], -1);
        while (maxv[1] <= 0) {
            ans--;
            update(1, 1, n, 1, pos[ans], 1);
        }
        printf(" %d", ans);
    }
    return 0;
}