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
int a[N];
map<int, int> mp[N];
int vis[N];
ll qpow(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int main() {
    int n;
    in >> n;
    for (int i = 1; i <= n; i++) in >> a[i];
    vector<int> li;
    for (int i = 1; i <= n; i++) {
        int tmp = a[i];
        for (int j = 2; j * j <= tmp; j++) {
            if (tmp % j == 0) {
                int x = 0;
                if (!vis[j]) {
                    vis[j] = 1;
                    li.push_back(j);
                }
                while (tmp % j == 0) {
                    tmp /= j;
                    x++;
                }
                mp[i][j] = x;
            }
        }
        if (tmp > 1) {
            if (!vis[tmp]) {
                vis[tmp] = 1;
                li.push_back(tmp);
            }
            mp[i][tmp] = 1;
        }
    }
    ll ans = 1;
    for (int i = 0; i < li.size(); i++) {
        int m1 = 1e9, m2 = 1e9;
        for (int j = 1; j <= n; j++) {
            if (m2 == 0) break;
            int x;
            if (!mp[j].count(li[i])) x = 0;
            else  x = mp[j][li[i]];
            if (x < m1) {
                m2 = m1;
                m1 = x;
            }
            else if (x == m1) {
                m2 = x;
            }
            else if (x < m2) m2 = x;
        }
        if (m2 == (int)1e9) m2 = 0;
        ans *= qpow(li[i], m2);
    }
    printf("%lld\n", ans);
    return 0;
}
