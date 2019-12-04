#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
char ans[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt = (n + 1) / 2;
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = 'T';
        }
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'R' && b > 0) {
                b--;
                now++;
                ans[i] = 'P';
            }
            if (s[i] == 'P' && c > 0) {
                c--;
                now++;
                ans[i] = 'S';
            }
            if (s[i] == 'S' && a > 0) {
                a--;
                now++;
                ans[i] = 'R';
            }
        }
        if (now >= cnt) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                if (ans[i] == 'T') {
                    if (a > 0) {
                        a--;
                        ans[i] = 'R';
                    }
                    else if (b > 0) {
                        b--;
                        ans[i] = 'P';
                    }
                    else if (c > 0) {
                        c--;
                        ans[i] = 'S';
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                printf("%c", ans[i]);
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}