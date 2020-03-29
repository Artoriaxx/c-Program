#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int a[N];
struct node {
    double val;
    int cnt;
    node(double val = 0, int cnt = 0): val(val), cnt(cnt) {}
};
node q[N * 2];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int t = 0;
    q[++t] = node(a[1], 1);
    for (int i = 2; i <= n; i++) {
        node x = node(a[i], 1);
        double tot = x.val;
        while (tot <= q[t].val * x.cnt && t) {
            x.cnt += q[t].cnt;
            tot += q[t].val * q[t].cnt;
            t--;
        }
        q[++t] = node(tot / x.cnt, x.cnt);
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= q[i].cnt; j++) {
            printf("%.9f\n", q[i].val);
        }
    }
    return 0;
}