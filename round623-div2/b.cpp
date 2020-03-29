#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int pos = 1;
        int tot = 0;
        bool flag = false;
        for (int i = len; i >= 1; i--) {
            if (i == len || s[i] == s[i + 1]) {
                continue;
            }
            else {
                if (i + 1 == len) continue;
                else if (s[i + 1] == 'A') tot += a;
                else tot += b;
                if (tot > p) {
                    pos = i + 1;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            if (s[1] == 'A') tot += a;
            else tot += b;
            if (tot <= p) puts("1");
            else {
                int i;
                for (i = 1; i <= len; i++) {
                    if (s[i] != s[1]) break;
                }
                printf("%d\n", min(i, len));
            }
            continue;
        }
        int res = pos;
        for (int i = pos + 1; i <= len; i++) {
            if (s[i] == s[pos]) res++;
            else break;
        }
        res++;
        if (res > len) res = len;
        printf("%d\n", res);
    }
    return 0;
}