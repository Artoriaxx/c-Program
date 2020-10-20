#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
struct point {
    ll x, y, val;
    point(ll x = 0, ll y = 0, ll val = 0): x(x), y(y), val(val) {}
    bool operator < (const point &b) const {
        return y - b.y == 0 ? x - b.x < 0 : y - b.y < 0;
    }
    //向量+
    point operator + (const point &b) const {
        return point(x + b.x, y + b.y, val);
    }
    //向量-
    point operator - (const point &b) const  {
        return point(x - b.x, y - b.y, val);
    }
    //叉积
    ll operator ^ (const point &b) const {
        return x * b.y - y * b.x;
    }
    //点积
    ll operator * (const point &b) const {
        return x * b.x + y * b.y;
    }
    //两点间距离
    ll dist(point b) {
        return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
    }
    void input() {
        in >> x >> y >> val;
    }
    void ouput() {
        printf("%lld %lld %lld\n", x, y, val);
    }
};
point p[N];
point tmp[N];
point rev[N];
int qua(point a) {
    ll x = a.x, y = a.y;
    if (x > 0 && y >= 0) return 1;
    if (x <= 0 && y > 0) return 2;
    if (x < 0 && y <= 0) return 3;
    if (x >= 0 && y < 0) return 4;
}
point c;
bool cmp(point a, point b) {
    return (a ^ b) >= 0;
}
bool cmp1(point a, point b) {
    if (qua(a) == qua(b)) return cmp(a, b);
    return qua(a) < qua(b);
}

//按极角排序，先找到最左下角的点
//重载point的<
int n;
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) p[i].input();
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                tmp[++cnt] = p[j] - p[i];
                rev[cnt] = p[i] - p[j];
                rev[cnt].val = p[j].val;
            }
        }
        sort(tmp + 1, tmp + cnt + 1, cmp1);
        sort(rev + 1, rev + cnt + 1, cmp1);
        ll l = p[i].val + tmp[1].val;
        ll r = p[i].val + tmp[1].val;
        for (int j = 2; j <= cnt; j++) {
            if (cmp1(tmp[j], point(0,0,0) - tmp[1])) l += tmp[j].val;
            else r += tmp[j].val;
        }
        ans = min(ans, abs(l - r));
        int k = 1;
        while (k <= cnt && cmp1(rev[k], tmp[1])) k++;
        for (int j = 2; j <= cnt; j++) {
            l -= tmp[j - 1].val;
            r += tmp[j].val;
            while (k <= cnt && cmp1(rev[k], tmp[j])) l += rev[k].val, r -= rev[k].val, k++;
            ans = min(ans, abs(l - r));
        }
        //for (int j = 1; j <= tot; j++) tmp[j].ouput();

    }
    printf("%lld\n", ans);
    return 0;
}