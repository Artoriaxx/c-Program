#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        vector<int> b, c;
        for (int i = 1; i <= n; i++) {
            if (a[i] & 1) b.push_back(i);
            else c.push_back(i);
        }
        if (c.size() > 0) {
            puts("1");
            printf("%d\n", c[0]);
        }
        else if (b.size() > 1) {
            printf("2\n");
            printf("%d %d\n", b[0], b[1]);
        }
        else puts("-1");
    }
    return 0;
}