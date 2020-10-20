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

const int N = 2e5 + 50;
ll a[N];
queue<int> q[40];
int pow2[40];
int main() {
    int n; in >> n;
    for (int i = 1; i <= n; i++) in >> a[i];
    pow2[0] = 1;
    for (int i = 1; i <= 30; i++) pow2[i] = 2 * pow2[i - 1];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        ll tmp = a[i];
        int cnt = 0;
        while (tmp) {
            if (tmp & 1) q[cnt].push(i);
            tmp >>= 1;
            cnt++;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 31; j >= 0; j--) {
            if ((a[i] >> j) & 1) continue;
            else {
                if (!q[j].empty()) {
                    int now = q[j].front();
                    q[j].pop();
                    if (now > i) continue;
                    a[now] -= pow2[j];
                    a[i] += pow2[j];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans + a[i] * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
