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

const int N = 55;
int pow10[N];
int aa = 100, bb = 100, cc = 100, dd = 100;
ll calc(int a, int b, int c, int d) {
    return 1ll * (aa + a) * (bb + b) * (cc + c) * (dd + d);
}
struct node {
    int a, b, c, d;
    bool operator < (const node &x) const {
        return calc(a, b, c, d) > calc(x.a, x.b, x.c, x.d);
    }
};
node s[N][N];

int cnt[N];
int k;
ll ans = 0;



int main() {
    pow10[0] = 1;
    for (int i = 1; i <= 9; i++) pow10[i] = pow10[i - 1] * 10;
    int tc; in >> tc;
    while (tc--) {
        ans = 0;
        int n; in >> n >> k;
        for (int i = 1; i <= k; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int t; node x;
            in >> t >> x.a >> x.b >> x.c >> x.d;
            int z = ++cnt[t];
            s[t][z] = x;
        }
        aa = bb = cc = dd = 100;
        for (int i = 1; i <= k; i++) {
            if (cnt[i] == 0) continue;
            sort(s[i] + 1, s[i] + cnt[i] + 1);
            aa += s[i][1].a;
            bb += s[i][1].b;
            cc += s[i][1].c;
            dd += s[i][1].d;
        }
        ans = 1ll * aa * bb * cc * dd;
        printf("%lld\n", ans);
    }
    return 0;
}
