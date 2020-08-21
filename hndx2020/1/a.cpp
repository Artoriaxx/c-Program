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
int main() {
    int n; cin >> n;
    map<string, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp1[s]++;
    }
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp2[s]++;
    }
    int ans = 0;
    for (auto v : mp1) {
        ans += min(mp1[v.first], mp2[v.first]);
    }
    printf("%d\n", ans);
    return 0;
}
