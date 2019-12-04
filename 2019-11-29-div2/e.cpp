#include <bits/stdc++.h>
#define lson (o << 1)
#define rson (o << 1 | 1)
using namespace std;
const int N = 1e6 + 50;
char s[N];
char ans[N];
int d[N];
int maxv[N << 2], minv[N << 2], sumv[N << 2];
int addv[N << 2];
void pushdown(int o, int l, int r) {
    if (addv[o]) {
        
        int mid = (l + r) >> 1;
        sumv[lson] += addv[o] * (mid - l + 1);
        sumv[rson] += addv[o] * (r - mid);
        maxv[lson] += addv[o]; maxv[rson] += addv[o];
        minv[lson] += addv[o]; minv[rson] += addv[o];
        addv[lson] += addv[o]; addv[rson] += addv[o];
        addv[o] = 0;
    }
    return;
}
void pushup(int o) {
    sumv[o] = sumv[lson] + sumv[rson];
    maxv[o] = max(maxv[lson], maxv[rson]);
    minv[o] = min(minv[lson], minv[rson]);
}
void update(int o, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        addv[o] += v;
        sumv[o] += v * (r - l + 1);
        maxv[o] += v;
        minv[o] += v;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(o, l, r);
    if (ql <= mid) update(lson, l, mid, ql, qr, v);
    if (qr > mid) update(rson, mid + 1, r, ql, qr, v);\
    pushup(o);
}
int query(int o, int l, int r, int pos) {
    if (l == r) {
        return sumv[o];
    }
    int mid = (l + r) >> 1;
    pushdown(o, l, r);
    if (pos <= mid) return query(lson, l, mid, pos);
    else return query(rson, mid + 1, r, pos);
}
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int now = 1;
    
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            now--;
            now = max(1, now);
        }
        else if (s[i] == 'R') {
            now++;
        }
        else if (s[i] == '(') {
            
            if (d[now] == 0) update(1, 1, N - 1, now, N - 1, 1);
            else if (d[now] == -1) {
                update(1, 1, N - 1, now, N - 1, 2);
            }
            d[now] = 1;
        }
        else if (s[i] == ')') {
            
            if (d[now] == 0) update(1, 1, N - 1, now, N - 1, -1);
            
            else if (d[now] == 1) {
                update(1, 1, N - 1, now, N - 1, -2);
            }
            d[now] = -1;
        }
        else {
            
            if (d[now] == -1) update(1, 1, N - 1, now, N - 1, 1);
            if (d[now] == 1) update(1, 1, N - 1, now, N - 1, -1);
            d[now] = 0;
        }
        int x = query(1, 1, N - 1, N - 1);
        if (x == 0 && minv[1] >= 0) {
            printf("%d ", maxv[1]);
        }
        else printf("-1 ");
    }
    return 0;
}