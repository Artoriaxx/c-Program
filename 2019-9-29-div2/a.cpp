#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
int check(int x) {
    int vis[15];
    memset(vis, 0, sizeof(vis));
    while (x) {
        if (vis[x % 10]) return 0;
        vis[x % 10] = 1;
        x /= 10;
    }
    return 1;
}
int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}