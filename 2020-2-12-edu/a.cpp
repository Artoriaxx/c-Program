#include <bits/stdc++.h>
using namespace std;
const int N = 150;
char s[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int l = 0, r = -1;
        for (int i = 1; i <= len; i++) {
            if (s[i] == '1') {
                if (!l) l = i;
                r = i;
            }
        }
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '0') ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}