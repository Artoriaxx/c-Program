#include <bits/stdc++.h>
using namespace std;
int vis[10005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int tot = 0, pos = 0;
    while (tot + pos / 2 <= m && pos < n) {
        tot += pos / 2;
        pos++;
    }
    if (pos == n && tot < m) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= pos; i++) printf("%d ", i);
    if (pos == n) {
        return 0;
    }
    for (int i = 1; i <= pos; i++) {
        for (int j = i + 1; j <= pos; j++) {
            vis[i + j]++;
        }
    }
    int res = m - tot;
    for (int i = pos + 1; i < 100005; i++) {
        if (vis[i] == res) {
            printf("%d ", i);
            break;
        }
    }
    for (int i = pos + 2; i <= n; i++) {
        printf("%d ", 10000000 + i * 5050);
    }
    return 0;
}