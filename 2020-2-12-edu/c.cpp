#include <bits/stdc++.h>
using namespace std;
const int N = 250;
char s[N];
vector<int> G[30];
int mp[30][30];
int vis[30];
void print(int x) {
    putchar('a' + x);
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i];
        if (vis[v]) continue;
        print(v);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 26; i++) G[i].clear();
        scanf("%s",s + 1);
        int len = strlen(s + 1);
        if (len == 1) {
            puts("YES");
            for (int i = 0; i < 26; i++) {
                putchar('a' + i);
            }
            puts("");
            continue;
        }
        for (int i = 1; i < len; i++) {
            if (!mp[s[i] - 'a'][s[i + 1] - 'a']) {
                G[s[i] - 'a'].push_back(s[i + 1] - 'a');
                G[s[i + 1] - 'a'].push_back(s[i] - 'a');
            }
            mp[s[i] - 'a'][s[i + 1] - 'a'] = mp[s[i + 1] - 'a'][s[i] - 'a'] = 1;
        }
        bool flag = true;
        int cnt1 = 0;
        for (int i = 0; i < 26; i++) {
            if (G[i].size() >= 3) {
                flag = false;
                break;
            }
            if (G[i].size() == 1) cnt1++;
        }
        if (cnt1 != 2) {
            flag = false;
        }
        if (!flag) {
            puts("NO");
            continue;
        }
        else {
            puts("YES");
            for (int i = 0; i < 26; i++) {
                if (G[i].size() == 1) {
                    print(i);
                    break;
                }
            }
            for (int i = 0; i < 26; i++) {
                if (!vis[i]) putchar('a' + i);
            }
            puts("");
        }
    }
    return 0;
}