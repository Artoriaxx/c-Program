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

const int N = 1e5 + 50;
int L[N * 300], R[N * 300], T[N];
int sum[N * 300];
int cnt;
int update(int pre, int l, int r, int x, int v) {
    int rt = ++cnt;
    int mid = (l + r) >> 1;
    L[rt] = L[pre], R[rt] = R[pre], sum[rt] = sum[pre] + v;
    if (l < r) {
		if (x <= mid) L[rt] = update(L[pre], l, mid, x, v);
		else R[rt] = update(R[pre], mid + 1, r, x, v);
    }
    return rt;
}
int querysum(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return sum[rt];
	int mid = (l + r) >> 1;
	int ans = 0;
	if (ql <= mid) ans += querysum(L[rt], l, mid, ql, qr);
	if (qr > mid) ans += querysum(R[rt], mid + 1, r, ql, qr);
	return ans;
}

int main() {
    int n; in >> n;
    map<int, int> mp, pos;
    for (int i = 1; i <= n; i++) {
        int x; in >> x;
        mp[x] = i; T[i] = T[i - 1];
        map<int, int> tmp;
        for (auto e : mp) tmp[e.first & x] = max(tmp[e.first & x], e.second); 
        for (auto e : tmp) {
            if (!pos.count(e.first)) {
                T[i] = update(T[i], 1, n, e.second, 1);
            }
            else {
                T[i] = update(T[i], 1, n, e.second, 1);
                T[i] = update(T[i], 1, n, pos[e.first], -1);
            }
            pos[e.first] = e.second;
        }
        mp = tmp;
    }
    int q; in >> q;
    int ans = 0;
    while (q--) {
        int l, r; in >> l >> r;
        l = (l ^ ans) % n + 1;
        r = (r ^ ans) % n + 1;
        if (l > r) swap(l, r);
        printf("%d\n", ans = querysum(T[r], 1, n, l, r));
    }
    return 0;
}
