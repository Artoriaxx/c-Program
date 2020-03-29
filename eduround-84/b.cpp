#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int vis[N];
vector<int> a[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            a[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int k;
            scanf("%d", &k);
            for (int j = 1; j <= k; j++) {
                int x;
                scanf("%d", &x);
                a[i].push_back(x);
            }
        }
        int pos = -1;
        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 0; j < a[i].size(); j++) {
                if (!vis[a[i][j]]) {
                    vis[a[i][j]] = 1;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                pos = i;
            }
        }
        if (pos == -1) puts("OPTIMAL");
        else {
            puts("IMPROVE");
            printf("%d ", pos);
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {

                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}