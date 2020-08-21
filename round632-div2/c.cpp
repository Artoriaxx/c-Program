/*
 * @Descripttion: 
 * @version: 
 * @Author: Artoriax
 * @Date: 2020-04-08 21:13:43
 * @LastEditors: Artoriax
 * @LastEditTime: 2020-04-09 00:44:01
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 50;
ll a[N], pre[N];
vector<int> pos[N];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    map<ll, int> mp;
    ll ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!mp.count(pre[i])) {
            mp[pre[i]] = ++cnt;
            pos[cnt].push_back(i);
        }
        else pos[mp[pre[i]]].push_back(i);
    }
    int tmp = n + 1;
    for (int i = n; i >= 1; i--) {
        int y = mp[pre[i - 1]];
        int l = 0, r = pos[y].size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[y][mid] >= i) {
                tmp = min(tmp, pos[y][mid]);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans += tmp - i;
    }
    printf("%lld\n", ans);
    return 0;
}
