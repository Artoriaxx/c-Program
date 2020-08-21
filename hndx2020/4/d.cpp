#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
ll tmp[N];
struct node {
    ll val; int id;
} a[N], b[N];
bool cmp(ll x, ll y) {
    return x > y;
}
bool cmp1(node x, node y) {
    return x.val > y.val;
}
int ans[N];
int main() {
    int n; ll m;
    scanf("%d%lld", &n, &m);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        int y;
        scanf("%lld%d", &tmp[i], &y);
        if (y == 1) a[++cnt1].val = tmp[i], a[cnt1].id = i;
        else b[++cnt2].val = tmp[i], b[cnt2].id = i;
    }
    sort(tmp + 1, tmp + n + 1, cmp);
    sort(a + 1, a + cnt1 + 1, cmp1);
    sort(b + 1, b + cnt2 + 1, cmp1);
    ll sum = 0;
    int k = 0;
    for (k = 1; k <= n; k++) {
        sum += tmp[k];
        if (sum >= m) break;
    }
    if (cnt1 >= k) {
        sum = 0;
        for (int i = 1; i <= k; i++) sum += a[i].val, ans[i] = a[i].id;
        if (sum >= m) {
            printf("%d %d\n", k, k);
            for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
            puts("");
        }
        else {
            int now = k;
            for (int i = 1; i <= cnt2; i++) {
                sum -= a[now].val;
                sum += b[i].val;
                ans[now] = b[i].id;
                now--;
                if (sum >= m) break; 
            }
            printf("%d %d\n", k, now);
            for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
            puts("");
        }
    }
    else {
        sum = 0;
        for (int i = 1; i <= cnt1; i++) sum += a[i].val, ans[i] = a[i].id;
        for (int i = 1; i <= k - cnt1; i++) sum += b[i].val, ans[cnt1 + i] = b[i].id;
        if (sum >= m) {
            printf("%d %d\n", k, cnt1);
            for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
            puts("");
        }
        else {
            int now = cnt1;
            for (int i = k - cnt1 + 1; i <= cnt2; i++) {
                sum -= a[now].val;
                sum += b[i].val;
                ans[now] = b[i].id;
                now--;
                if (sum >= m) break; 
            }
            printf("%d %d\n", k, now);
            for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
            puts("");
        }
    }
    return 0;
}
