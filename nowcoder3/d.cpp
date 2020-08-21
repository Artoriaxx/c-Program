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

const int N = 2e5 + 50;
int main() {
    int t; in >> t;
    while (t--) {
        int n, m;
        in >> n >> m;
        if (m > 4 * n || (m & 1)) puts("No");
        else {
            
            int a, b, mn = 1e9;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i * j >= n && (i + j) * 2 < mn) {
                        mn = 2 * (i + j);
                        a = i, b = j;
                    }
                }
            }
            vector<pii> ans;
            vector<pii> ans2;
            int tmp = n;
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    ans.push_back(pii(i, j));
                    tmp--;
                    if (tmp == 0) break;
                }
            }
            int now = 2 * (a + b);
            if (m < now) {
                puts("No");
                continue;
            }
            puts("Yes");
            int x = 1e8, y = 1e8;
            while (now < m) {
                pii p = ans.back();
                if (p.second == 1 || p.first == 1) {
                    ans.pop_back();
                    now += 2;
                    ans2.push_back(pii(--x, --y));
                }
                else {
                    ans.pop_back();
                    now += 4;
                    ans2.push_back(pii(--x, --y));
                }
            }
            if (now > m) {
                ans2.pop_back();
                pii p = ans.back();
                ans.push_back(pii(p.first + 1, p.second));
            }
            for (auto e : ans) printf("%d %d\n", e.first, e.second);
            for (auto e : ans2) printf("%d %d\n", e.first, e.second);
        }
    }
    return 0;
}
