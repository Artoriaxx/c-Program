#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int up[N], down[N], vis[N];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    int cnt1 = 0, cnt2 = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (vis[x] == 0) down[++cnt1] = x;
        if (vis[x] == 1) up[++cnt2] = x;
        if (vis[x] == 2) {
            flag = false;
        } 
        vis[x]++;
    }
    if (flag) {
        cout << "YES" << endl;
        cout << cnt2 << endl;
        sort (up + 1, up + cnt2 + 1);
        for (int i = 1; i <= cnt2; i++) {
            cout << up[i] << " ";
        }
        cout << endl << cnt1 << endl;
        sort (down + 1, down + cnt1 + 1, cmp);
        for (int i = 1; i <= cnt1; i++) {
            cout << down[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}