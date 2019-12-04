#include <bits/stdc++.h>
using namespace std;
int a[305][305];
int main() {
    int n;
    scanf("%d", &n);
    int num = 0;
    for (int j = 1; j <= n; j++){
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++){
                a[i][j] = ++num;
            }
        }
        else {
            for (int i = n; i >= 1; i--){
                a[i][j] = ++num;
            }
        }
        
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ",a[i][j]);
        }
        puts("");
    }
    return 0;
}