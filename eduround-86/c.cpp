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
ll pre[N];
int main() {
    int t; in >> t;
    while (t--) {
        ll a, b, q;
        in >> a >> b >> q;
        if (a > b) swap(a, b);
        ll tot = 0;
        for (int i = 1; i <= a * b; i++) pre[i] = 0;
        for (int i = 1; i <= a * b; i++) {
            if ((i % a) % b != (i % b) % a) {
                pre[i]++;
            }
        }
        for (int i = 1; i <= a * b; i++) pre[i] += pre[i - 1];
        while (q--) {
            ll l, r;
            in >> l >> r;
            l--;
            ll x = l / (a * b);
            ll y = r / (a * b);
            ll ans = 0;
            ans = pre[a * b] * y + pre[r % (a * b)] - (pre[a * b] * x + pre[l % (a * b)]); 
            printf("%lld ", ans); 
        }
        printf("\n");
        
    }
    return 0;
}
