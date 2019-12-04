#include <bits/stdc++.h>
using namespace std;
vector<int> ve[1005];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++) {
            ve[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            ve[x].push_back(i);
        }
        int ans = 0;
        int tmp = n / 2;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < min(ve[i].size(), ve[i].size() / k); j++) {
                if (ve[i][j] <= tmp) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}