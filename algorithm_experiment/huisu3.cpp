#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[4][4];
int ans = 0;
int n;
void dfs(int cnt, int now) {
    if (cnt >= n * n) {
        if (now <= ans) return;
        for (int i = 0; i < n; i++) {
            int f = 0;
            for (int j = 0; j < n; j++) {
                if (mp[i][j] == 'o') {
                    if (f == 1) return;
                    else f = 1;
                }
                if (mp[i][j] == 'X') {
                    f = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int f = 0;
            for (int j = 0; j < n; j++) {
                if (mp[j][i] == 'o') {
                    if (f == 1) return;
                    else f = 1;
                }
                if (mp[j][i] == 'X') {
                    f = 0;
                }
            }
        }
        ans = now;
        return;
    }
    if (mp[cnt / n][cnt % n] == 'X') dfs(cnt + 1, now);
    else {
        mp[cnt / n][cnt % n] = 'o';
        dfs(cnt + 1, now + 1);
        mp[cnt / n][cnt % n] = '.';
        dfs(cnt + 1, now);
    }
}
int main() {
    while (~scanf("%d", &n) && n) {
        ans = 0;
        for (int i = 0; i < n; i++) scanf("%s", mp[i]);
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
