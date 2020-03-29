#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int r;
        bool flag = false;
        for (int i = 1; i <= d; i = r + 1) {
            r = d / (d / i);
            int ans = r - 1 + ceil((double)d / r);
            if (ans <= n) {
                flag = true;
                break;
            }
        }
        if (flag) puts("YES");
        else puts("NO");

    }
    return 0;
}