#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
vector<int> ans;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int tmp = 0;
        ans.clear();
        int now = 1;
        while (tmp != 1) {
            tmp = n / now;
            int l = now, r = n;
            int c = 1e9 + 5;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (n / mid < tmp) {
                    c = min(c, mid);
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            now = c;
            ans.push_back(tmp);
        }
        ans.push_back(0);
        
        printf("%d\n", ans.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            printf("%d ", ans[i]);
        }
        puts("");
    }
    return 0;
}