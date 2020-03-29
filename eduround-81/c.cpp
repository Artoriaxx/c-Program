#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];
char t[N];
vector<int> pos[30];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        int n = strlen(s + 1);
        int m = strlen(t + 1);
        
        for (int i = 0; i < 26; i++) pos[i].clear();
        for (int i = 1; i <= n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (pos[t[i] - 'a'].size() == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        int now = 0;
        int cnt = 1;
        for (int i = 1; i <= m; i++) {
            int x = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), now) - pos[t[i] - 'a'].begin();
            if (x >= pos[t[i] - 'a'].size()) {
                cnt++;
                int y = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), 0) - pos[t[i] - 'a'].begin();
                now = pos[t[i] - 'a'][y];
            }
            else {
                now = pos[t[i] - 'a'][x];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}