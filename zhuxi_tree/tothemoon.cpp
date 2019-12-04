#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
const int N = 1e6 + 10;
ll a[N];
int L[N * 40], R[N * 40], T[N];
ll sum[N * 40];
ll addv[N * 40];
int vis[N * 40];
int cnt;
void pushup(int rt) {
    sum[rt] = sum[L[rt]] + sum[R[rt]];
}
void copy(int x,int y) {
    sum[x] = sum[y];
    addv[x] = addv[y];
    L[x] = L[y];
    R[x] = R[y];
}
void pushdown(int x,int l,int r) {
    if(vis[x]) {
        int now = ++cnt;
        copy(now, L[x]);
        L[x] = now;
        now = ++cnt;
        copy(now, R[x]);
        R[x] = now;
        vis[L[x]] = vis[R[x]] = 1; //
        vis[x] = 0;
    }
    if(addv[x]) {
        int m = (l+r)/2;
        addv[L[x]] += addv[x];
        addv[R[x]] += addv[x];
        sum[L[x]] += 1ll*addv[x]*(m-l+1);
        sum[R[x]] += 1ll*addv[x]*(r-m);
        addv[x] = 0;
    }
}
int build(int l, int r) {
    int rt = ++cnt;
    sum[rt] = addv[rt] = 0;
    if (l == r) {
        sum[rt] = a[l];
        return rt;
    }
    int mid = (l + r) >> 1;
    if (l < r) {
        L[rt] = build(l, mid);
        R[rt] = build(mid + 1, r);
    }
    pushup(rt);
    return rt;
}
int update(int pre, int l, int r, int ql, int qr, ll v) {
    int rt = ++cnt;
    int mid = (l + r) >> 1;
    if (ql == l && r == qr) {
        L[rt] = L[pre], R[rt] = R[pre];
        sum[rt] = sum[pre] + (ll)(r - l + 1) * v;
        addv[rt] = addv[pre] + v;
        vis[rt] = l == r ? 0 : 1;
        return rt;
    }
    pushdown(pre, l, r);
    if (qr <= mid) {
        L[rt] = update(L[pre], l, mid, ql, qr, v);
        R[rt] = R[pre];
    }
    else if (ql > mid) {
        R[rt] = update(R[pre], mid + 1, r, ql, qr, v);
        L[rt] = L[pre];
    }
    else {
        L[rt] = update(L[pre], l, mid, ql, mid, v);
        R[rt] = update(R[pre], mid + 1, r, mid + 1, qr, v);
    }
    pushup(rt);
    return rt;
}
ll query(int rt, int l, int r, int ql, int qr) {
    if (ql == l && r == qr) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    ll ans = 0;
    pushdown(rt, l, r);
    if (qr <= mid) return query(L[rt], l, mid, ql, qr);
    else if (ql > mid) return query(R[rt], mid + 1, r, ql ,qr);
    else return query(L[rt], l, mid, ql, mid) + query(R[rt], mid + 1, r, mid + 1, qr);
    return ans;
}
int main() {
    while (~scanf("%d%d", &n, &q)) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        cnt = 0;
        T[0] = build(1, n);
        int now = 0;
        for (int i = 1; i <= q; i++) {
            char ch[2];
            int l, r; ll v;
            int t;
            scanf("%s", ch);
            if (ch[0] == 'Q') {
                scanf("%d%d", &l, &r);
                printf("%lld\n", query(T[now], 1, n, l, r));
            }
            if (ch[0] == 'C') {
                scanf("%d%d%lld", &l, &r, &v);
                now++;
                T[now] = update(T[now - 1], 1, n, l, r, v);
            }
            if (ch[0] == 'H') {
                scanf("%d%d%d", &l, &r, &t);
                printf("%lld\n", query(T[t], 1, n, l, r));
            }
            if (ch[0] == 'B') {
                scanf("%d", &t);
                now = t;
            }
        }
    }
    return 0;
}
