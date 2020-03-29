#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
vector<int> a[N], res, now;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x, v;
        scanf("%d%d", &x, &v);
        if (!x) continue;
        if (a[x].size() == 0) res.push_back(x);
        a[x].push_back(v);
        ans += v;
    }
    for (int i = 0; i < res.size(); i++) sort(a[res[i]].begin(), a[res[i]].end());
    int cnt = n, sum = ans;
    for (int i = 1; i <= n; i++) {
        now.clear();
        if (res.size() == 0) break;
        for (int j = 0; j < res.size(); j++) {
            sum -= a[res[j]].back();
            cnt--;
            q.push(a[res[j]].back());
            a[res[j]].pop_back();
            if (a[res[j]].size()) now.push_back(res[j]);
        }
        while (cnt <= i && q.size()) {
            sum += q.top(); q.pop();
            cnt++;
        }
        if (cnt > i) ans = min(ans, sum);
        res.clear();
        for (int j = 0; j < now.size(); j++) res.push_back(now[j]);
    }
    printf("%d\n", ans);
    return 0;
}