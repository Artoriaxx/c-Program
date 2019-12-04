#include <bits/stdc++.h>
#define N 150
using namespace std;
char s[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        sort (s + 1, s + len + 1);
        bool flag = true;
        for (int j = 2; j <= len; j++) {
            if (s[j] != s[j - 1] + 1) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}