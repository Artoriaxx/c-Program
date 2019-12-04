#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    char c = getchar();
    for (int i = 1; i <= n / 2; i++) {
        c = getchar();
        if (isdigit(c)) sum1 += c - '0';
        else cnt1++;
    }
    for (int i = 1; i <= n / 2; i++) {
        c = getchar();
        if (isdigit(c)) sum2 += c - '0';
        else cnt2++;
    }
    if (sum1 == sum2) {
        if (cnt1 != cnt2) puts("Monocarp");
        else puts("Bicarp");
    }
    else if (sum1 > sum2) {
        if (cnt1 >= cnt2) puts("Monocarp");
        else {
            int x = cnt2 - cnt1; x >>= 1;
            if (sum1 != sum2 + 9 * x) puts("Monocarp");
            else puts("Bicarp");
        }
    }
    else {
        if (cnt2 >= cnt1) puts("Monocarp");
        else {
            int x = cnt1 - cnt2; x >>= 1;
            if (sum2 != sum1 + 9 * x) puts("Monocarp");
            else puts("Bicarp");
        }
    }
    return 0;
}