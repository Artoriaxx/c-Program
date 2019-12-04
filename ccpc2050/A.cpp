#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        if (len % 4 != 0) {
            cout << "No" << endl;
        }
        else {
            int now = 0;
            bool flag = true;
            for (int i = 1; i <= len; i++) {
                now++;
                if (now == 1 && s[i] == '2') continue;
                if (now == 2 && s[i] == '0') continue;
                if (now == 3 && s[i] == '5') continue;
                if (now == 4 && s[i] == '0') {
                    now = 0;
                    continue;
                }
                flag = false;
                break;
            }
            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}