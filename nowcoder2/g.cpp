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
bitset<N> ans, bs;
pair<int, int> a[N], b[N];
int main() {
    int n, m; in >> n >> m;
    for (int i = 0; i < n; i++) {
        in >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        in >> b[i].first;
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + m);
    ans.set();
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (j >= 0 && a[j].first >= b[i].first) {
            bs.set(a[j].second);
            j--;
        }
        ans &= bs >> b[i].second;
    }
    printf("%d\n", ans.count());
    return 0;
}
