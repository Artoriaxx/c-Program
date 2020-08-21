#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ios {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x) {
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
ll a[N], b[N], c[N];
ll f(ll a, ll b, ll c) {
    return a * a + b * b + c * c;
}
int main() {
    int t; in >> t;
    while (t--) {
        int A, B, C;
        in >> A >> B >> C;
        for (int i = 1; i <= A; i++) in >> a[i];
        for (int i = 1; i <= B; i++) in >> b[i];
        for (int i = 1; i <= C; i++) in >> c[i];
        sort(a + 1, a + A + 1);
        sort(b + 1, b + B + 1);
        sort(c + 1, c + C + 1);
        vector<int> tmp1, tmp2;
        ll ans = 9e18;
        for (int i = 1; i <= A; i++) {
            int x = lower_bound(b + 1, b + B + 1, a[i]) - b;
            tmp1.clear(); tmp2.clear();
            if (x == B + 1) {
                tmp1.push_back(b[B]);
            }
            else if (x == 1) {
                tmp1.push_back(b[1]);
            }
            else {
                tmp1.push_back(b[x]);
                tmp1.push_back(b[x - 1]);
            }
            x = lower_bound(c + 1, c + C + 1, a[i]) - c;
            if (x == C + 1) {
                tmp2.push_back(c[C]);
            }
            else if (x == 1) {
                tmp2.push_back(c[1]);
            }
            else {
                tmp2.push_back(c[x]);
                tmp2.push_back(c[x - 1]);
            }
            for (int j = 0; j < tmp1.size(); j++) {
                for (int k = 0; k < tmp2.size(); k++) {
                    ans = min(ans, f(a[i] - tmp1[j], tmp1[j] - tmp2[k], tmp2[k] - a[i]));
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
