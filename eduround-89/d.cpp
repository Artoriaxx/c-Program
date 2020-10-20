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

const int N = 5e5 + 50;
const int M = 1e7 + 50;
int a[N];
vector<int> s;
int ans1[N], ans2[N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int p[M], notp[M];
int mnp[M];
int main() {
    int cnt = 0;
    for (int i = 2; i <= 1e7; i++) {
        if (!notp[i]) p[++cnt] = i, mnp[i] = i;
        for (int j = 1; j <= cnt && i * p[j] <= 1e7; j++) {
            mnp[i*p[j]] = p[j];
            notp[i*p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
    int n; in >> n;
    for (int k = 1; k <= n; k++) {
        in >> a[k];
        int tmp = a[k];
        s.clear();
        int now = 1;
        while (tmp % mnp[a[k]] == 0) tmp /= mnp[a[k]], now *= mnp[a[k]];
        s.push_back(now);
        
        if (tmp > 1) s.push_back(tmp);
        if (s.size() == 1) ans1[k] = ans2[k] = -1;
        else {
            ans1[k] = s[0];
            ans2[k] = s[1];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans1[i]);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d ", ans2[i]);
    return 0;
}
