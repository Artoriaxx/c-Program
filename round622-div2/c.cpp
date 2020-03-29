#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
typedef long long ll;
int m[N];
ll pre[N];
ll last[N];
int ans[N];
int st[N][24], lg2[N];
int rmq(int l, int r) {
    if (l > r) return 0;
    else {
        int x = lg2[r - l + 1];
        return min(st[l][x], st[r - (1 << x) + 1][x]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &m[i]);
    for (int i = 1; i <= n; i++) {
        st[i][0] = m[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; (i + (1 << j) - 1) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    ll mx = m[1];
    for (int i = 1; i <= n; i++) {
        if (m[i] <= mx) {
            pre[i] = m[i] * i;
            mx = m[i];
        }
        else {
            int l = 1, r = i - 1;
            int pos = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (rmq(mid, i) < m[i]) {
                    l = mid + 1;
                    pos = max(pos, mid);
                }
                else r = mid - 1;
            }
            pre[i] = pre[pos] + (ll)(i - pos) * (ll)m[i];
        }
    }
    mx = m[n];
    for (int i = n; i >= 1; i--) {
        if (m[i] <= mx) {
            last[i] = m[i] * (n - i + 1);
            mx = m[i];
        }
        else {
            int l = i + 1, r = n;
            int pos = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (rmq(i, mid) < m[i]) {
                    pos = min(pos, mid);
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            last[i] = last[pos] + (ll)(pos - i) * (ll)m[i];
        }
    }
    mx = -1;
    int pos;
    for (int i = 1; i <= n; i++) {
        if (pre[i] + last[i] - m[i] > mx) {
            mx = pre[i] + last[i] - m[i];
            pos = i;
        }
    }
    int maxx = m[pos];
    ans[pos] = m[pos];
    for (int i = pos - 1; i >= 1; i--) {
        if (m[i] < maxx) maxx = m[i];
        ans[i] = maxx;
    }
    maxx = m[pos];
    for (int i = pos + 1; i <= n; i++) {
        if (m[i] < maxx) maxx = m[i];
        ans[i] = maxx;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]); 
    return 0;
}