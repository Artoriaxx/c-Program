#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
char s[N];
const ll p = 1e9 + 7;
ll f[N];
int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    f[0] = 1;
    bool flag = true;
    for (int i = 1; i <= len; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            flag = false;
            break;
        }
    }
    if (!flag) puts("0");
    else {
        for (int i = 1; i <= len; i++) {
            if (i > 1 && s[i] == 'u' && s[i - 1] == 'u') {
                f[i] = (f[i - 1] + f[i - 2]) % p;
            }
            else if (i > 1 && s[i] == 'n' && s[i - 1] == 'n') {
                f[i] = (f[i - 1] + f[i - 2]) % p;
            }
            else f[i] = f[i - 1];
        }
        printf("%lld\n", f[len] % p);
    }
    return 0;
}