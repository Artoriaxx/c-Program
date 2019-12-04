#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)){
        int tot = a + b;
        int ans = 0;
        while (tot) {
            int tmp = tot / c;
            ans += tmp;
            if (tmp == 0) break;
            tot = tot % c;
            tot += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}