#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char ss[N];
vector<char> s;

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", ss + 1);
    for (int i = 1; i <= n; i++) {
        s.push_back(ss[i]);
    }
    int ans = 0;
    while (1) {
        int pos = -1;
        int maxx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[i + 1] == s[i] - 1) {
                    if (s[i] > maxx) {
                        pos = i;
                        maxx = s[i];
                    }
                }
            }
            else if (i == s.size() - 1) {
                if (s[i - 1] == s[i] - 1) {
                    if (s[i] > maxx) {
                        pos = i;
                        maxx = s[i];
                    }
                }
            }
            else {
                if (s[i + 1] == s[i] - 1 || s[i - 1] == s[i] - 1) {
                    if (s[i] > maxx) {
                        pos = i;
                        maxx = s[i];
                    }
                }
            }
        }
        if (pos == -1) {
            break;
        }
        ans++;
        auto it = s.begin();
        it += pos;
        s.erase(it);
    }
    printf("%d\n", ans);
    return 0;
}