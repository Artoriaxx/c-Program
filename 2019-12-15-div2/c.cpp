#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
const ll p = 1e9 + 7;
char s[2 * N], t[2 * N];
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int x;
        scanf("%d", &x);
        ll len = 0;
        scanf("%s", s + 1);
        int llen = strlen(s + 1);
        len = strlen(s + 1);
        strcpy(t + 1, s + 1);
        int now = 1;
        
        while (llen < x) {
            int cnt = t[now] - '0';
            int tmplen = llen;
            cnt--;
            while (cnt) {
                cnt--;
                if (llen >= x) break;
                for (int i = llen + 1, j = 1; i <= llen + tmplen - now; i++, j++) {
                    t[i] = t[now + j];
                }
                llen += tmplen - now;
            }
            now++;
        }
        for (int i = 1; i <= x; i++) {
            len = (i + (len - i) % p * (t[i] - '0') % p + p) % p;
        }
        printf("%lld\n", len);
    }
    return 0;
}