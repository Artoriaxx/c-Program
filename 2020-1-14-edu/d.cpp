#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 50;
int a[N][10];
vector<int> v[N];
map<int, int> mp;
void dfs(int i, int d, int t, int ans) {
    if (d >= t) {
        mp[ans] = i;
        return;
    }
    dfs(i, d + 1, t, ans * 10 + v[i][d]);
    dfs(i, d + 1, t, ans);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int l = 0, r = 1e9 + 50;
    int ans1, ans2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            for (int j = 1; j <= m; j++) {
                if (a[i][j] >= mid) {
                    v[i].push_back(j);
                }
            }
            dfs(i, 0, v[i].size(), 0);
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            int ans = 0;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] < mid) {
                    ans = ans * 10 + j;
                }
            }
            if (mp.count(ans)) {
                ans1 = i;
                ans2 = mp[ans];
                flag = true;
                break;
            }
        }
        if (!flag) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}