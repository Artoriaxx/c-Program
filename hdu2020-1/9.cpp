#include <bits/stdc++.h>
#define pii pair<int, int>
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

const int N = 5e4 + 50;
pii a[N];
int q[N];
pii t[N];
int main() {
    int tc; in >> tc;
    while (tc--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) {
            in >> a[i].first >> a[i].second;
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        map<pii, int> mp;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i + 1]) {
                mp[a[i]] = 1;
            }
        }
        int m = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i].second > a[m].second) a[++m] = a[i];
        }
        int l = 1, r = 0;
        t[1] = pii(0, 1);
        for (int i = 1; i <= m; i++) {
            while (l <= r) {
                t[i] = pii(a[q[r]].first - a[i].first, a[i].second - a[q[r]].second);
                if (1ll * t[i].first * t[q[r]].second <= 1ll * t[i].second * t[q[r]].first) r--;
                else break; 
            }
            q[++r] = i;
        }
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (!mp.count(a[q[i]])) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
