#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef Artoriax
        return getchar();
    #endif
        const int LEN = 1 << 18 | 1;
        static char buf[LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)), s == t ? -1 : *s++;
    }
    inline READ & operator >> (char *s) {
        char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) *s++ = ch, ch = read(); *s = '\0';
        return *this;
    }
    inline READ & operator >> (string &s) {
        s = ""; char ch;
        while (isspace(ch = read()) && ~ch);
        while (!isspace(ch) && ~ch) s += ch, ch = read();
        return *this;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        char ch, flag;
        for(ch = read(),flag = 0; !isdigit(ch) && ~ch; ch = read()) flag |= ch == '-';
        for(x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
        flag && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
const int inf = 0x3f3f3f3f;
int a[10][N];
struct seg {
#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
#define pii pair<int, int>
    int id; pii mn[N << 2];
    void build(int o, int l, int r) {
        if (l == r) { mn[o] = pii(a[id][l], inf); return; }
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(mn[o], mn[ls], mn[rs]);
    }
    void pushup(pii &o, pii lm, pii rm) {
        if (lm.first > rm.first) {
            o.first = rm.first;
            o.second = min(rm.second, lm.first);
        }
        else if (lm.first < rm.first){
            o.first = lm.first;
            o.second = min(lm.second, rm.first);
        }
        else o = pii(lm.first, lm.first);
    }
    void update(int o, int l, int r, int x, int v) {
        if (l == r) { mn[o] = pii(v, inf); return; }
        if (x <= mid) update(ls, l, mid, x, v);
        else update(rs, mid + 1, r, x, v);
        pushup(mn[o], mn[ls], mn[rs]);
    }
    pii ask(int o, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) return mn[o];
        if (qr <= mid) return ask(ls, l, mid, ql, qr);
        else if (ql > mid) return ask(rs, mid + 1, r , ql, qr);
        else {
            pii lm = ask(ls, l, mid, ql, mid);
            pii rm = ask(rs, mid + 1, r, mid + 1, qr);
            pii ans;
            pushup(ans, lm, rm);
            return ans;
        }
    }
    
    int query(int o, int l, int r, int ql, int qr) {
        pii ans = ask(o, l, r, ql, qr);
        if (ans.first == inf || ans.second == inf) return 2 * inf;
        return ans.first + ans.second; 
    }
} t[10];

int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, tmp; in >> x; tmp = x; 
        for (int j = 0; j < 10; j++) {
            if (tmp % 10) a[j][i] = x;
            else a[j][i] = inf;
            tmp /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        t[i].id = i;
        t[i].build(1, 1, n);
    }
    while (m--) {
        int op, x, y; in >> op >> x >> y;
        if (op == 1) {
            int tmp = y;
            for (int j = 0; j < 10; j++) {
                if (tmp % 10) t[j].update(1, 1, n, x, y);
                else t[j].update(1, 1, n, x, inf);
                tmp /= 10;
            }
        }
        else {
            int ans = 2 * inf;
            for (int j = 0; j < 10; j++) ans = min(ans, t[j].query(1, 1, n, x, y));
            if (ans == 2 * inf) puts("-1");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
