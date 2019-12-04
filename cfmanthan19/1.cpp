#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
int n = 20;
int a[N][N];
int ans[N][N];
bool flag1 = false;
void dfs(int x) {
    //if (flag1) return;
    if (x >= n * n) {
        int res = -1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j <= n; j++) {
                tmp ^= a[i][j];
            }
            if (res == -1) res = tmp;
            else if (res != tmp) {
                flag = false;
                break;
            }
        }
        if (!flag) return;
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 1; j <= n; j++) {
                tmp ^= a[j][i];
            }
            if (res != tmp) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%d ", a[i][j]);
                    
                }
                printf("\n");
            }
            flag1 = true;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == -1) {
                a[i][j] = x;
                dfs(x + 1);
                a[i][j] = -1;
            }
            else continue;
        }
    }
}
int main() {
    freopen("1.txt", "w", stdout);
    memset(a, -1, sizeof(a));
    dfs(0);
    
    return 0;
}