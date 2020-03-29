#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 50;
char s[N];
char mx[N];
char a[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        memset(s, '\0', sizeof(s));
        memset(mx, '\0', sizeof(mx));
        memset(a, '\0', sizeof(a));
        int n; scanf("%d%s", &n, s + 1);
        int now = 1;
        for (int i = 1; i <= n; i++) mx[i] = s[i];
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            for (int j = i; j <= n; j++) a[++cnt] = s[j];
            if ((n - i + 1) & 1) {
                for (int j = i - 1; j >= 1; j--) a[++cnt] = s[j];
            }
            else {
                for (int j = 1; j < i; j++) a[++cnt] = s[j];
            }
            if (strcmp(a + 1, mx + 1) < 0) {
                now = i;
                for (int j = 1; j <= n; j++) mx[j] = a[j];
            }
        }
        printf("%s\n", mx + 1);
        printf("%d\n", now);
    }
    return 0;
}