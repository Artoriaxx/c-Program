#include <bits/stdc++.h>
#define mid (l+r>>1)
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

const int N = 2e6 + 50;
const int inf = 0x3f3f3f3f;
multiset<int> st;
map<int, int> mp;
int mn[N << 2], L[N << 2], R[N << 2], tot, rt;
void pushup(int o) {
    mn[o] = min(mn[L[o]], mn[R[o]]);
}
void update(int &o, int l, int r, int x, int v) {
    if (!o) o = ++tot;
    if (l == r) {
        mn[o] = v;
        return;
    }
    if (x <= mid) update(L[o], l, mid, x, v);
    else update(R[o], mid + 1, r, x, v);
    pushup(o);
}
int query(int o, int l, int r, int ql, int qr) {
    if (!o) return inf;
    if (l == ql && r == qr) return mn[o];
    if (qr <= mid) return query(L[o], l, mid, ql, qr);
    else if (ql > mid) return query(R[o], mid + 1, r, ql, qr);
    else return min(query(L[o], l, mid, ql, mid), query(R[o], mid + 1, r, mid + 1, qr));
}
void ins(int x) {
    mp[x]++;
    if (!st.size()) {
        st.insert(x);
        return;
    }
    if (mp[x] == 1) {
        auto it = mp.lower_bound(x);
        ++it;
        if (it != mp.end() && it->second == 1) update(rt, 1, 1e9, it->first, it->first - x);
        --it;
        int y = -1e9;
        if (it != mp.begin()) y = prev(it)->first;
        update(rt, 1, 1e9, x, x - y);
    }
    else if (mp[x] == 2) update(rt, 1, 1e9, x, 0);
    st.insert(x);
}
void del(int x) {
    auto it = mp.lower_bound(x);
    mp[x]--;
    int y = -1e9;
    if (it != mp.begin()) y = prev(it)->first;
    if (mp[x] == 0) {
        if ((++it) != mp.end() && it->second == 1) {
            update(rt, 1, 1e9, it->first, it->first - y);
        }
        update(rt, 1, 1e9, x,  inf);
        mp.erase(x);
    }
    else if (mp[x] == 1) update(rt, 1, 1e9, x, x - y);
    st.erase(st.lower_bound(x));
}
void calc(int x) {
    bool ok = false;
    if (st.size() < 2) {
        puts("No");
        return;
    }
    auto it = st.upper_bound(x);
    int a = -inf, b = -inf;
    if (it != st.begin()) a = *(--it);
    if (it != st.begin()) b = *(--it);
    if (a + b > x) ok = true;
    if (query(rt, 1, 1e9, x, 1e9) < x) ok = true;
    if (ok) puts("Yes");
    else puts("No");
}
int main() {
    int q; in >> q;
    memset(mn, inf, sizeof(mn));
    while (q--) {
        int op, x; in >> op >> x;
        if (op == 1) ins(x);
        else if (op == 2) del(x);
        else calc(x);
    }
    return 0;
}
