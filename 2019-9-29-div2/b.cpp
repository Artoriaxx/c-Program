#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
typedef long long ll;
const ll p = 1e9 + 7;
int r[N], c[N];
int mp[N][N];
int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 1; i <= w; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= r[i]; j++) {
            mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= c[i]; j++) {
            mp[j][i] = 1;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            printf("%d ", mp[i][j]);
        }
        puts("");
    }
    bool flag = true;
    for (int i = 1; i <= h; i++) {
        if (mp[i][r[i] + 1] == 1) {
            flag = false;
            break;
        }
    }
    for (int i = 1; i <= w; i++) {
        if (mp[c[i] + 1][i] == 1) {
            flag = false;
            break;
        }
    }
    if (!flag) puts("0");
    else {
        ll ans = 1;
        for (int i = 1; i <= h; i++) {
            for (int j = r[i] + 2; j <= w; j++) {
                if (i >= c[j] + 2) {
                    ans = (ans * 2) % p;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}