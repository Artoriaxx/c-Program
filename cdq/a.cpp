#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
struct node {
    int a, b, c;
    int cnt;
    int ans;
    bool operator == (const node &x) const {
        return a == x.a && b == x.b && c == x.c;
    }
} p[N];
int n, k;
bool cmp1(node x, node y) {
    if (x.a == y.a) {
        if (x.b == y.b) {
            return x.c < y.c;
        }
        return x.b < y.b;
    }
    return x.a < y.a;
}
bool cmp2(node x, node y) {
    if (x.b == y.b) return x.c < y.c;
    return x.b < y.b;
}
int d[N];
void update(int x, int v) {
    for (int i = x; i <= k; i += i & (-i)) d[i] += v;
}
int query(int x) {
    int anss = 0;
    for (int i = x; i; i -= i & (-i)) anss += d[i];
    return anss;
}
void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid + 1, r);
    sort(p + l, p + mid + 1, cmp2); sort(p + mid + 1, p + r + 1, cmp2);
    int j = l;
    for (int i = mid + 1; i <= r; i++) {
        while (j <= mid && p[j].b <= p[i].b) {
            update(p[j].c, p[j].cnt);
            j++;
        }
        p[i].ans += query(p[i].c);
    }
    for (int i = l; i < j; i++) {
        update(p[i].c, -p[i].cnt);
    }
}
int res[N];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
        p[i].cnt = 1;
        p[i].ans = 0;
    }
    sort(p + 1, p + n + 1, cmp1);
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && p[i] == p[i - 1]) p[num].cnt++;
        else p[++num] = p[i], p[num].cnt = 1;
    }
    cdq(1, num);
    for (int i = 1; i <= num; i++) {
        res[p[i].ans + p[i].cnt - 1] += p[i].cnt;
    }
    for (int i = 0; i < n; i++) printf("%d\n", res[i]);
    return 0;
}