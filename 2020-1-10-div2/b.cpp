#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
ll a[N];
ll pre[N], last[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
        }
        pre[0] = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
            if (pre[i] <= 0) flag = false;
        }
        last[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            last[i] = last[i + 1] + a[i];
            if (last[i] <= 0) flag = false;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
/*
3
4
1 2 3 4
3
7 4 -1
3
5 -5 5
*/