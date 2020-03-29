#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
char s[N];
int ans[N];
int main() {
    int n;
    scanf("%d", &n);
    int sum = 1;
    for (int i = 1; i <= n; i++) sum *= 10;
    for (int i = 0; i < sum; i++) {
        int now = i;
        for (int j = 1; j <= n; j++) {
            s[n - j + 1] = now % 10;
            now /= 10; 
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j == 1 || s[j] == s[j - 1]) {
                cnt++;
            }
            else {
                ans[cnt]++;
                cnt = 1;
            }
        }
        if (cnt) ans[cnt]++;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}