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

const int N = 3e5 + 50;
int a[N], b[N];
int change(int x, int v) {
    int ans = 0;
    if (a[x] > a[x - 1] && a[x] > a[x + 1]) ans = -a[x];
    if (a[x] < a[x - 1] && a[x] < a[x + 1]) ans += a[x];
    if (a[x - 1] > v && a[x + 1] > v) {
        ans += -v;
    }
    else if (a[x - 1] > v && a[x + 1] < v) {
        ans += a[x - 1];
    }
    else if (a[x - 1] < v && a[x + 1] > v) {
        ans += a[x + 1];
    }
    else if (a[x - 1] < v && a[x + 1] < v) {
        ans += v;
    }
    return ans;
}
int main() {
    int t; in >> t;
    while (t--) {
        int n, q; in >> n >> q;
        for (int i = 1; i <= n; i++) in >> a[i];
        int now = 1;
        int r = 1;
        b[1] = a[1];
        a[0] = 0, a[n+1] = 0;
        for (int i = 2; i <= n; i++) {
            if (now) {
                if (a[i] < b[r]) {
                    now = 0;
                    b[++r] = a[i];
                }
                else {
                    b[r] = a[i];
                }
            }
            else {
                if (a[i] > b[r]) {
                    now = 1;
                    b[++r] = a[i];
                }
                else b[r] = a[i];
            }
        }
        ll ans = 0, sum = 0;
        for (int i = 1; i <= r; i++) {
            if (i & 1) sum += b[i];
            else sum -= b[i];
            ans = max(ans, sum);
        }
        printf("%lld\n", ans);
        while (q--) {
            int l, r; in >> l >> r;
            ans += change(r, a[l]);
            ans += change(l, a[r]);
            swap(a[l], a[r]);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
