#include<bits/stdc++.h>
using namespace std;
char s[10500];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ans = 0;
        int a = 0, b = 0;
        int c = 0;
        for (int j = 1; j <= len; j++) {
            if (s[j] == 'A') a++;
            else if (s[j] == 'B') b++;
            else c++;
            if ((a + c >= 11 || b + c >= 11) && abs(a - b) + c >= 2) {
                ans++;
                
                a = 0, b = 0, c = 0;
            }
        }
        cout << ans << endl;
    }
	return 0;
}
