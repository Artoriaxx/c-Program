#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int n;
int L, R;
bool check(int x) {
    L = 0, R = 1e9;
    int tmp = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1) {
            if (i > 1 && a[i - 1] == -1) {
                L = max(L, a[i] - x);
                R = min(R, a[i] + x);
            }
            if (i < n && a[i + 1] == -1) {
                L = max(L, a[i] - x);
                R = min(R, a[i] + x);
            }
        }
    }
    return L <= R;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ansl, ansr;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        check(1);
        int l = 0, r = 1e9;
        for (int i = 1; i <= n; i++) {
            if (a[i] != -1) {
                if (i > 1 && a[i - 1] != -1) {
                    l = max(l, abs(a[i] - a[i - 1]));
                }
            }
        }
        int ans = 1e9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                if (mid < ans) {
                    ans = mid;
                    ansl = L;
                    ansr = R;
                }
            }
            else l = mid + 1;
        }
        if (ansl < 0) ansl = 0;
        printf("%d %d\n", ans, ansl);
    }
    return 0;
}