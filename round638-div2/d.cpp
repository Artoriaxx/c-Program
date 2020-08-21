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
int main() {
    int t; in >> t;
    while (t--) {
        ll n; in >> n;
        if (n == 2) {
            puts("1");
            puts("0");
            continue;
        }
        n--;
        ll sum = 0, now = 2;
        vector<ll> ans;
        while (sum + now <= n) {
            sum += now;
            ans.push_back(now);
            now <<= 1;
        }
        if (n - sum > 0) ans.push_back(n - sum);
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        int l = 1;
        for (int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i] - l); l = ans[i];
        }
        puts("");
    }
    return 0;
}
