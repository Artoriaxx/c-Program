#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
char s[N];
int sum[30][N];
int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int m;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 26; j++) {
            sum[j][i] = sum[j][i - 1] + ((s[i] - 'a') == j);
        }
    }
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r == l) {
            puts("YES");
            continue;
        }
        if (s[l] != s[r]) {
            puts("YES");
            continue;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (('a' + i) == s[l]) {
                continue;
            }
            ans += ((sum[i][r - 1] - sum[i][l]) > 0);
        }
        //printf("%d\n", ans);
        if (ans >= 2) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}