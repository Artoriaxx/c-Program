#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
map<int, int> mp;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, s, k;
        scanf("%d%d%d", &n, &s, &k);
        mp.clear();
        for (int i = 1; i <= k; i++) {
            int x;
            scanf("%d", &x);
            mp[x] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= max(s - 1, n - s); i++) {
            if (s + i <= n && !mp.count(s + i)) {
                ans = i;
                break;
            }
            else if (s - i >= 1 && !mp.count(s - i)) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}