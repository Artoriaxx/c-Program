#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
ll a[N];
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        priority_queue<ll, vector<ll>, greater<ll> > q;
        while (!q.empty()) q.pop();
        for (int i = 1; i <= n; i++) {
            if (a[i] > 2048) continue;
            q.push(a[i]);
        }
        bool flag = false;
        while (!q.empty()) {
            ll x = q.top(); q.pop();
            if (x == 2048) {
                flag = true;
                break;
            }
            if (q.empty()) break;
            ll y = q.top(); q.pop();
            if (x == y) {
                q.push(x + y);
            }
            else {
                q.push(y);
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}