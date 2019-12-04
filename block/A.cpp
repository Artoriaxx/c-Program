#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int l[N], r[N], belong[N], num[N], pos[N], a[N];
void build() {
    int size = sqrt((double)n + 0.5);
    int cnt = n / size;
    if (n % cnt != 0) cnt++;
    for (int i = 1; i <= cnt; i++) {
        l[i] = (i - 1) * size + 1;
        r[i] = i * size;
    }
    r[cnt] = n;
    for (int i = 1; i <= n; i++) {
        belong[i] = (i - 1) / size + 1;
    }
    for (int i = n; i >= 1; i--) {
        if (i + a[i] > r[belong[i]]) {
            num[i] = 1;
            pos[i] = i + a[i];
        }
        else {
            num[i] = num[i + a[i]] + 1;
            pos[i] = pos[i + a[i]];
        }
    }
}
void update(int now, int val) {
    a[now] = val;
    for (int i = now; i >= l[belong[now]]; i--) {//只需修改本块
        if (i + a[i] > r[belong[i]]) {
            num[i] = 1;
            pos[i] = i + a[i];
        }
        else {
            num[i] = num[i + a[i]] + 1;
            pos[i] = pos[i + a[i]];
        }
    }
}
int query(int now) {
    int ans = 0;
    while (now <= n) {
        ans += num[now];
        now = pos[now];
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build();
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int p, x, y;
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d", &x);
            printf("%d\n", query(x + 1));
        }
        else {
            scanf("%d%d", &x, &y);
            update(x + 1, y);
        }
    }
    return 0;
}