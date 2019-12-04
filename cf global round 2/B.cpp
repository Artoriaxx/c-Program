#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
int tmp[N];
bool cmp(int a, int b) {
    return a > b;
}
int n, h;
bool check(int x) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= x; i++) {
        tmp[i] = a[i];
    }
    sort (tmp + 1, tmp + x + 1, cmp);
    bool flag = true;
    int nowh = 0;
    for (int i = 1; i <= x; i += 2) {
        if (nowh + tmp[i] <= h) {
            nowh += tmp[i];
        }
        else {
            flag = false;
            break;
        }
    }
    return flag;
}
int main() {
    
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}