#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
char s[N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        if (s[n] == 'o' && s[n - 1] == 'p') {
            puts("FILIPINO");
        }
        else if ((s[n] == 'u' && s[n - 1] == 's' && s[n - 2] == 'e' && s[n - 3] == 'd') || (s[n] == 'u' && s[n - 1] == 's' && s[n - 2] == 'a' && s[n - 3] == 'm')) {
            puts("JAPANESE");
        }
        else puts("KOREAN");
    }
    return 0;
}