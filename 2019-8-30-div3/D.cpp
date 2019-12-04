#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int cnt[N];
int num[N];
int a[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int res = 1e9;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        while (a[i]) {
            cnt[a[i]]++;
            num[a[i]] += tmp;
            if (cnt[a[i]] == k) {
                res = min(res, num[a[i]]);
            }
            tmp++; a[i] /= 2;
        }
    }
    printf("%d\n", res);
    return 0;
}