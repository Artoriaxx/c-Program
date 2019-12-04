#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
int n, m;
int belong[N], a[N];
struct node {
    map<int, int> mp;
    int l, r, color;
    int len() {
        return r - l + 1;
    }
} block[1500];
void build() {
    int size = sqrt((double)n + 0.5);
    int cnt = n / size;
    if (n % cnt != 0) cnt++;
    for (int i = 1; i <= cnt; i++) {
        block[i].l = (i - 1) * size + 1;
        block[i].r = i * size;
        block[i].mp.clear();
        block[i].color = -1;
    }
    block[cnt].r = n;
    for (int i = 1; i <= n; i++) {
        belong[i] = (i - 1) / size + 1;
    }
    for (int i = 1; i <= n; i++) {
        block[belong[i]].mp[a[i]]++;
    }
}
void pushdown(int x) {
    if (~block[x].color) {
        for (int i = block[x].l; i <= block[x].r; i++) {
            a[i] = block[x].color;
        }
        block[x].mp.clear();
        block[x].mp[block[x].color] = block[x].len();
        block[x].color = -1;
    }
}
void update(int l, int r, int z) {
    int L = belong[l], R = belong[r];
    for (int i = L + 1; i < R; i++) {
        block[i].color = z;
    }
    if (L != R) {
        pushdown(L); pushdown(R);
        for (int i = l; i <= block[L].r; i++) {
            block[L].mp[a[i]]--;
            block[L].mp[z]++;
            a[i] = z;
        }
        for (int i = block[R].l; i <= r; i++) {
            block[R].mp[a[i]]--;
            block[R].mp[z]++;
            a[i] = z;
        }
    }
    else {
        pushdown(L);
        for (int i = l; i <= r; i++) {
            block[L].mp[a[i]]--;
            block[L].mp[z]++;
            a[i] = z;
        }
    }
}
ll query(int l, int r, int z) {
    ll ans = 0;
    int L = belong[l], R = belong[r];
    for (int i = L + 1; i < R; i++) {
        if (~block[i].color) {//如果这上面有之前的lazy标记，那原mp中颜色作废，WA*4
            if (block[i].color == z)
                ans += block[i].len();
        }
        else if (block[i].mp.count(z) != 0) {
            ans += block[i].mp[z];
        }
    }
    if (L != R) {
        pushdown(L); pushdown(R);
        for (int i = l; i <= block[L].r; i++) {
            ans += (a[i] == z);
        }
        for (int i = block[R].l; i <= r; i++) {
            ans += (a[i] == z);
        }
    }
    else {
        pushdown(L);
        for (int i = l; i <= r; i++) {
            ans += (a[i] == z);
        }
    }
    return ans;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        build();
        while (m--) {
            int q, l, r, z;
            scanf("%d%d%d%d", &q, &l, &r, &z);
            l++; r++;
            if (q == 1) {
                update(l, r, z);
            }
            else {
                printf("%lld\n", query(l, r, z));
            }
        }
    }
    return 0;
}