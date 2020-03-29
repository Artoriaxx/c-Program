#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
char s[N];
ll num[N][30];
ll ans[30][30];
int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            num[i][j] = num[i + 1][j];
        }
        num[i][s[i] - 'a']++;
    }
    ll res = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 26; j++) {
            ans[s[i] - 'a'][j] += num[i + 1][j];
            res = max(res, ans[s[i] - 'a'][j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        res = max(res, num[1][i]);
    }
    printf("%lld\n", res);
    return 0;
}