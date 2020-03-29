#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dis[1000][1000];
struct node {
    ll x, y;
    node(ll x = 0, ll y = 0): x(x), y(y) {}
};
vector<node> p;
int main() {
    ll x0, y0, ax, ay, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    ll xs, ys, t;
    scanf("%lld%lld%lld", &xs, &ys, &t);
    p.push_back(node(x0, y0));
    ll t1 = x0, t2 = y0;
    while (t1 <= xs + t) {
        t1 = ax * t1 + bx;
        t2 = ay * t2 + by;
        p.push_back(node(t1, t2));
    }
    int n = p.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
        }
    }
    ll tmp = t;
    int tans = 0;
    for (int pos = 0; pos < n; pos++) {
        for (int i = pos; i >= 0; i--) {
            tmp = t;
            int ans = 0;
            tmp -= abs(xs - p[pos].x) + abs(ys - p[pos].y);
            if (tmp >= 0) {
                ans++;
                int res = pos;
                for (int j = pos - 1; j >= pos - i; j--) {
                    tmp -= dis[j][j + 1];
                    if (tmp >= 0) {
                        ans++;
                        res = j;
                    }
                    else {
                        tmp += dis[j][j + 1];
                        break;
                    }
                }
                int now = pos + 1;
                while (tmp >= 0 && now < n) {
                    tmp -= dis[res][now];
                    if (tmp >= 0) {
                        res = now;
                        now++;
                        ans++;
                    }
                    else {
                        break;
                    }
                }
            }
            tans = max(tans, ans);
        }
    }
    
    
    printf("%d\n", tans);
    return 0;
}