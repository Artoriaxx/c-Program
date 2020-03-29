#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                cnt++;
                a[i]++;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
        }
        if (sum == 0) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}