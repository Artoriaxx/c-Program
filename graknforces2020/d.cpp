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

const int N = 2e3 + 50;
int a[N], b[N], c[N], d[N];
struct node {
    int x, y;
    bool operator < (const node &bb) const {
        if (x == bb.x) return y < bb.y;
        return x < bb.x;
    }
};
int mx[N*N];
int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= n; i++) in >> a[i] >> b[i];
    for (int i = 1; i <= m; i++) in >> c[i] >> d[i];
    vector<node> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[j] >= a[i] && d[j] >= b[i]) {
                s.push_back(node{c[j] - a[i] + 1, d[j] - b[i] + 1});
            }
        }
    }
    sort(s.begin(), s.end());
    for (int i = s.size() - 1; i >= 0; i--) {
        mx[i] = max(mx[i+1], s[i].y);
    }
    int ans = mx[0];
    for (int i = 0; i < s.size(); i++) {
        ans = min(ans, s[i].x + mx[i+1]);
    }
    printf("%d\n", ans);
    return 0;
}
