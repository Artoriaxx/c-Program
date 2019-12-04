#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int f[N];
string s[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int cnt[N][30];
int vis[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        f[i] = i;
    }
    sort (s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            cnt[i][s[i][j] - 'a'] = 1;
            //cout << s[i][j] - 'a' << " ";
        }
        //cout << endl;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] == 1 && cnt[i + 1][j] == 1) {
                int x = find(i), y = find(i + 1);
                f[x] = y;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) find(i);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[f[i]]) {
            vis[f[i]] = 1;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}