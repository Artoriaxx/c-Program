#include <bits/stdc++.h>
#define N 50010
using namespace std;
int a[N];
struct node {
    long long l, r, cnt, id;
    bool operator < (const node &b) const {
        return cnt == b.cnt ? r < b.r : cnt < b.cnt;
    }
} Q[N];
struct Ans {
    long long x, y;
} ans[N];
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long color[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long size = sqrt((double)n + 0.5);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld", &Q[i].l, &Q[i].r);
        Q[i].cnt = Q[i].l / size;
        Q[i].id = i;
    }
    sort (Q + 1, Q + m + 1);
    int l = 1, r = 0;
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        while (l < Q[i].l) {
            res -= color[a[l]] * color[a[l]];
            color[a[l]]--;
            res += color[a[l]] * color[a[l]];
            l++;
        }
        while (l > Q[i].l) {
            l--;
            res -= color[a[l]] * color[a[l]];
            color[a[l]]++;
            res += color[a[l]] * color[a[l]];
        }
        while (r < Q[i].r) {
            r++;
            res -= color[a[r]] * color[a[r]];
            color[a[r]]++;
            res += color[a[r]] * color[a[r]];
        }
        while (r > Q[i].r) {
            res -= color[a[r]] * color[a[r]];
            color[a[r]]--;
            res += color[a[r]] * color[a[r]];
            r--;
        }
        
        long long tmp = res - (Q[i].r - Q[i].l + 1);
        long long denom = (Q[i].r - Q[i].l + 1LL) * (Q[i].r - Q[i].l);
        long long g = gcd(tmp, denom);
        ans[Q[i].id].x = tmp / g;
        ans[Q[i].id].y = denom / g;
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld/%lld\n", ans[i].x, ans[i].y);
    }
    return 0;
}