#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    string s[6] = {
        "abc", "acb", "bca", "bac", "cba", "cab"
    };
    int ans = -1;
    for (int i = 0; i < 6; i++) {
        bool flag = true;
        for (int j = 0; j < 3; j++) {
            if (s[i][j] == a[0] && s[i][(j + 1) % 3] == a[1]) {
                flag = false;
                break;
            }
            if (s[i][j] == b[0] && s[i][(j + 1) % 3] == b[1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = i;
            break;
        }
    }
    if (ans != -1) {
        puts("YES");
        for (int i = 1; i <= n; i++) {
            cout << s[ans];
        }
        printf("\n");
        return 0;
    }
    for (int i = 0; i < 6; i++) {
        bool flag = true;
        for (int j = 0; j < 2; j++) {
            if (s[i][j] == a[0] && s[i][(j + 1) % 3] == a[1]) {
                flag = false;
                break;
            }
            if (s[i][j] == b[0] && s[i][(j + 1) % 3] == b[1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = i;
            break;
        }
    }
    if (ans != -1) {
        puts("YES");
        for (int i = 1; i <= n; i++) printf("%c", s[ans][0]);
        for (int i = 1; i <= n; i++) printf("%c", s[ans][1]);
        for (int i = 1; i <= n; i++) printf("%c", s[ans][2]);
        return 0;
    }
    puts("NO");
    return 0;

}