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

const int N = 3e5 + 50;
ll ans = 0;
int a[N];
ll f[N][2];
void dfs(vector<int> s, int pos) {
    if (s.size() == 0) return;
    if (pos < 0) return;
    vector<int> s1, s0;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >> pos) & 1) s1.push_back(s[i]);
        else {
            s0.push_back(s[i]);
            ans += s1.size();
        }
    }
    f[pos][0] += ans;
    ll len0 = s0.size(), len1 = s1.size();
    f[pos][1] += len0 * len1 - ans;
    dfs(s0, pos - 1);
    dfs(s1, pos - 1);
}
int main() {
    int n; in >> n;
    vector<int> s;
    for (int i = 1; i <= n; i++) in >> a[i], s.push_back(a[i]);
    dfs(s, 30);
    ll ans = 0, x = 0;
    for (int i = 30; i >= 0; i--) {
        if (f[i][0] <= f[i][1]) {
            ans += f[i][0];
        }
        else {
            ans += f[i][1];
            x += (1 << i);
        }
    }
    printf("%lld %lld\n", ans, x);
    return 0;
}
