#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
struct node {
    int a, b;
} p[N];
int posa[N], posb[N];
int d[N];
void update(int x) {
    for (int i = x; i < N; i += i & (-i)) d[i] += 1;
}
int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & (-i)) ans += d[i];
    return ans;
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].a);
        posa[p[i].a] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].b);
        posb[p[i].b] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (query(N - posb[p[i].a]) > 0) ans++;
        update(N - posb[p[i].a]);
    }
    printf("%d\n", ans);
    return 0;
}