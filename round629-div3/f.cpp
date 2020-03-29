#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int a[N];
ll pre[N];
ll last[N];
ll pcnt[N];
ll lcnt[N];
struct node {
    ll val;
    ll cnt;
    node() {}
    node(ll val, ll cnt): val(val), cnt(cnt) {}
} p[N];
int main() {
    int n, k; scanf("%d%d", &n, &k);
    pre[0] = last[n + 1] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        p[++cnt] = node(a[i], 1);
        while (i < n && a[i + 1] == a[i]) {
            i++;
            p[cnt].cnt++;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        pcnt[i] = pcnt[i - 1] + p[i].cnt;
        pre[i] = pre[i - 1] + p[i].val * p[i].cnt; 
    }
    for (int i = cnt; i >= 1; i--) {
        lcnt[i] = lcnt[i + 1] + p[i].cnt;
        last[i] = last[i + 1] + p[i].val * p[i].cnt; 
    }
    ll mn = 1e18;
    for (int i = 1; i <= cnt; i++) {
        if (p[i].cnt >= k) {
            mn = 0;
            break;
        }
        if (pcnt[i] >= k) {
            mn = min(mn, pcnt[i - 1] * (p[i].val - 1) - pre[i - 1] + k - p[i].cnt);
        }
        if (lcnt[i] >= k) {
            mn = min(mn, last[i + 1] - lcnt[i + 1] * (p[i].val + 1) + k - p[i].cnt);
        }
        mn = min(mn, pcnt[i - 1] * (p[i].val - 1) - pre[i - 1] + last[i + 1] - lcnt[i + 1] * (p[i].val + 1) + k - p[i].cnt);
        
    }
    printf("%lld\n", mn);
    

    return 0;
}