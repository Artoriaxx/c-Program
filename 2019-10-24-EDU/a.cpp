#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char s[N];
int vis[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        memset(vis, 0, sizeof(vis));
        vector<char> ans;
        ans.clear();
        for (int i = 1; i <= len; i++) {
            int j = i;
            while (j <= len && s[j] == s[i]) j++;
            j--;
            if ((j - i + 1) % 2 == 1 && !vis[s[i] - 'a']) {
                ans.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
            }  
            i = j;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        puts("");
    }
    return 0;
}