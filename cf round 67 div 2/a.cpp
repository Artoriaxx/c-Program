#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char ch1[N];
char s[N];
vector<int> ve[30];
int num[30];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", ch1 + 1);
    for (int i = 1; i <= n; i++) {
        ve[ch1[i] - 'a'].push_back(i);
        num[ch1[i] - 'a']++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ans = 0;
        for (int j = 1; j <= len; j++) {
            int tmp = ve[s[j] - 'a'].size();
            ans = max(ans, ve[s[j] - 'a'][tmp - num[s[j] - 'a']]);
            num[s[j] - 'a']--;
        }
        for (int j = 1; j <= len; j++) {
            num[s[j] - 'a']++;
        }
        printf("%d\n", ans);
    }
    return 0;
}