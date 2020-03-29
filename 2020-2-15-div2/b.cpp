#include <bits/stdc++.h>
using namespace std;
char s[150][100];
int is[150];
int vis[150];
vector<int> ans1, ans2, ans3;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        is[i] = 1;
        for (int j = 1; j <= m / 2; j++) {
            if (s[i][j] != s[i][m - j + 1]) {
                is[i] = 0;
                break;
            }
        }
        if (is[i]) ans2.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool flag = true;
            for (int k = 1; k <= m; k++) {
                if (s[i][k] != s[j][m - k + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag && !vis[i] && !vis[j]) {
                ans1.push_back(i);
                ans3.push_back(j);
                vis[i] = vis[j] = 1;
            }
        }
    }
    int sze = ans1.size() + ans3.size();
    for (int i = 0; i < ans2.size(); i++) {
        if (!vis[ans2[i]]) {
            sze++;
            break;
        }
    }
    printf("%d\n", sze * m);
    for (int i = 0; i < ans1.size(); i++) {
        printf("%s", s[ans1[i]] + 1);
    }
    for (int i = 0; i < ans2.size(); i++) {
        if (!vis[ans2[i]]) {
            printf("%s", s[ans2[i]] + 1);
            break;
        }
    }
    for (int i = ans3.size() - 1; i >= 0; i--) {
        printf("%s", s[ans3[i]] + 1);
    }
    return 0;
}