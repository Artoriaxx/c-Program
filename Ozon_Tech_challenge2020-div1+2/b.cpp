#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
char s[N];
vector<int> ans[N];
int vis[N];
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int cnt = 1;
    while (1) {
        int l = 1, r = n;
        bool flag = false;
        for (; l < r; l++) {
            if (vis[l]) continue;
            if (s[l] == '(') {
                for (; r > l; r--) {
                    if (vis[r]) continue;
                    if (s[r] == ')') {
                        flag = true;
                        ans[cnt].push_back(l);
                        ans[cnt].push_back(r);
                        vis[l] = 1;
                        vis[r] = 1;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            cnt--;
            break;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%d\n", ans[i].size());
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}