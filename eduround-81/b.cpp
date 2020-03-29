#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        scanf("%s", s + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') sum++;
            else sum--;
        }
        if (sum == 0) {
            int tmp = 0;
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                if (s[i] == '0') tmp++;
                else tmp--;
                if (tmp == x) {
                    flag = true;
                    break;
                }
            }
            if (flag) puts("-1");
            else puts("0");
        }
        else {
            int tot = 0;
            int ans = 0;
            if (x == 0) ans++;
            for (int i = 1; i <= n; i++) {
                if (s[i] == '0') tot++;
                else tot--;
                if ((x - tot) % sum == 0 && (x - tot) / sum >= 0) {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}