#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
string s[20];
int vis[20];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i <= 9; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            vis[s[i][3] - '0'] = 1;
        }
        map<string, int> mp;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mp.count(s[i])) {
                for (int j = 0; j <= 9; j++) {
                    if (!vis[j]) {
                        cnt++;
                        s[i][3] = j + '0';
                        vis[j] = 1;
                        break;
                    }
                }
            }
            mp[s[i]] = 1;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++) {
            cout << s[i] << "\n";
        }
    }
    return 0;
}