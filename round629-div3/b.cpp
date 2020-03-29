#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 50;
char s[N];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        string ans1 = "";
        string ans2 = "";
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '2') {
                if (!f) {
                    ans1 += "1";
                    ans2 += "1";
                }
                else {
                    ans1 += "0";
                    ans2 += "2";
                }
            }
            else if (s[i] == '1') {
                if (!f) {
                    ans1 += "1";
                    ans2 += "0";
                    f = 1;
                }
                else {
                    ans1 += "0";
                    ans2 += "1";
                }
            }
            else if (s[i] == '0') {
                ans1 += "0";
                ans2 += "0";
            }
        }
        cout << ans1 << endl << ans2 << endl;
    }
    return 0;
}