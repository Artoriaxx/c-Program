#include <bits/stdc++.h>
#define N 50005
using namespace std;
typedef long long ll;
const int M = sqrt(N) + 5;
struct node {
    int l, r, id, cnt;
    bool operator < (const node &b) const {
        return cnt == b.cnt ? r < b.r : cnt < b.cnt;
    }
    node (int l = 0, int r = 0, int id = 0, int cnt = 0): l(l), r(r), id(id), cnt(cnt) {}
} Q[N * 5];
int n, q, size;
int a[N];
int cnt1[N], cnt2[N];
ll ans[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    size = sqrt((double)n + 0.5);
    scanf("%d", &q);
    int tot = 0;
    for (int i = 1; i <= q; i++) {//将询问拆成四个
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        Q[++tot] = node(r1, r2, i, r1 / size);
        Q[++tot] = node(l1 - 1, r2, -i, (l1 - 1) / size);
        Q[++tot] = node(l2 - 1, r1, -i, (l2 - 1) / size);
        Q[++tot] = node(l1 - 1, l2 - 1, i, (l1 - 1) / size);
    }
    sort (Q + 1, Q + tot + 1);
    int l = 0, r = 0; ll sum = 0;
    for (int i = 1; i <= tot; i++) {
        while (l < Q[i].l) l++, sum += cnt2[a[l]], cnt1[a[l]]++;
        while (l > Q[i].l) sum -= cnt2[a[l]], cnt1[a[l]]--, l--;
        while (r < Q[i].r) r++, sum += cnt1[a[r]], cnt2[a[r]]++;
        while (r > Q[i].r) sum -= cnt1[a[r]], cnt2[a[r]]--, r--;
        if (Q[i].id > 0) ans[Q[i].id] += sum;
        else ans[-Q[i].id] -= sum;
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}