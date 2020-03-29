#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
map<int, int> mp[2];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int cnt = 0;
    for (int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        if (mp[x][y]) {
            mp[x][y] = 0;
            if (y == 1) {
                if (mp[!x][y]) {
                    cnt--;
                }
                if (mp[!x][y + 1]) {
                    cnt--;
                }
            }
            else if (y == n) {
                if (mp[!x][y]) {
                    cnt--;
                }
                if (mp[!x][y - 1]) {
                    cnt--;
                }
            }
            else {
                if (mp[!x][y]) {
                    cnt--;
                }
                if (mp[!x][y - 1]) {
                    cnt--;
                }
                if (mp[!x][y + 1]) {
                    cnt--;
                }
            }
        }
        else {
            mp[x][y] = 1;
            if (y == 1) {
                if (mp[!x][y]) {
                    cnt++;
                }
                if (mp[!x][y + 1]) {
                    cnt++;
                }
            }
            else if (y == n) {
                if (mp[!x][y]) {
                    cnt++;
                }
                if (mp[!x][y - 1]) {
                    cnt++;
                }
            }
            else {
                if (mp[!x][y]) {
                    cnt++;
                }
                if (mp[!x][y - 1]) {
                    cnt++;
                }
                if (mp[!x][y + 1]) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }

    return 0;
}