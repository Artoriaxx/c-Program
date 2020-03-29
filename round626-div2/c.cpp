#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char s[N];
int main() {
    int n;
    scanf("%d%s", &n, s + 1);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') x++;
        else y++;
    }
    if (x != y) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    stack<int> s1, s2;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            s1.push(i);
            if (s1.size() == s2.size()) {
                ans += 2 * s1.size();
                while (!s1.empty()) s1.pop();
                while (!s2.empty()) s2.pop();
            }
        }
        else {
            if (s2.size() == 0) {
                if (s1.size()) {
                    s1.pop();
                }
                else s2.push(i);
            }
            else {
                s2.push(i);
                if (s1.size() == s2.size()) {
                    ans += 2 * s1.size();
                    while (!s1.empty()) s1.pop();
                    while (!s2.empty()) s2.pop();
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}