#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1e9 + 7;
int initial = 1050;
int digit[105];
int dp[105][2050][2][2];
int dfs(int pos, int dif, int f1, int f2) {
    if (pos == 0) return dif > initial;
    if (dp[pos][dif][f1][f2] != -1) return dp[pos][dif][f1][f2];
    int sz = f1 ? digit[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= sz; i++) {
        int sz2 = f2 ? i : 9;
        for (int j = 0; j <= sz2; j++) {
            ans = (ans + dfs(pos - 1, dif + j - i, f1 && (i == sz), f2 && (j == sz2))) % p;
        }
    }
    dp[pos][dif][f1][f2] = ans;
    return ans;
}
char s[105];
int calc(char s[]) {
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
        digit[len - i + 1] = s[i] - '0';
    }
    return dfs(len, initial, 1, 1);
}
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%s", s + 1);
    printf("%d\n", calc(s));
    return 0;
}