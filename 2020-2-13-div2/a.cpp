#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char a[N], b[N], c[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s%s", a + 1, b + 1, c + 1);
        int len = strlen(a + 1);
        bool flag = true;
        for (int i = 1; i <= len; i++) {
            if (b[i] == c[i] || a[i] == c[i]);
            else {
                flag = false;
                break;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}