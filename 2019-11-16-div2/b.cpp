#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int a[N];
int vis[N];
int vis1[N];
vector<int> ans;
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int d = 1;
    int cnt = 0;
    bool flag = true;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (vis[a[i]] != 0) {
                flag = false;
                break;
            }
            if (vis1[a[i]] == d) {
                flag = false;
                break;
            }
            cnt++;
            vis[a[i]] = d;
            vis1[a[i]] = d;
        }
        else {
            if (vis[-a[i]] == 0) {
                flag = false;
                break;
            }
            else {
                vis[-a[i]] = 0;
                cnt--;
                if (cnt == 0) {
                    d++;
                    ans.push_back(i - last);
                    last = i;
                }
            }
        }
    }
    if (cnt != 0) flag = false;
    if (flag) {
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
    } 
    else puts("-1");
    return 0;
}