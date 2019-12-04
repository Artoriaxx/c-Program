#include <bits/stdc++.h>
#define N 505
using namespace std;
int mat[N][N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            mat[i][j] = mat[i][j] ^ x;
        }
    }
    // printf("----------------------------------\n");
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] == 1) res++;
        }
        if (res % 2 != 0) {
            flag = false;
            // cout << i << " " << endl;
        }
    }
    for (int i = 1; i <= m; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (mat[j][i] == 1) res++;
        }
        if (res % 2 != 0) {
            flag = false;
            // cout << "gg " << i << " " << endl;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}