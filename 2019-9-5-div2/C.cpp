#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
char s[N];
int num[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int num0 = 0, num1 = 0;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') num0++;
            if (s[i] == '1') {
                num[i] = num0;
                num0 = 0;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                ll now = 0;
                int len = 0;
                for (int j = i; j <= n; j++) {
                    now = now * 2 + s[j] - '0';
                    if (now >= (int)1e6) break;
                    len++;
                    if (num[i] + len >= now) {
                        ans++;
                    }
                    else break;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}