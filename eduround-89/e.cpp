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
const int mod = 998244353;
int a[N], b[N];
int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= m; i++) in >> b[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[a[i]] = i;
    
    for (int i = 1; i <= m; i++) {
        if (!mp.count(b[i])) {
            printf("0\n");
            return 0;
        }
    }
    int ans = 1;
    int pos = mp[b[1]];
    for (int i = 1; i <= pos; i++) {
        if (a[i] < b[1]) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 1; i < m; i++) {
        int l = mp[b[i]], r = mp[b[i+1]];
        if (r < l) {
            printf("0\n");
            return 0;
        }
        for (int j = l; j <= r; j++) {
            if (a[j] < b[i]) {
                printf("0\n");
                return 0;
            }
        }
        for (int j = l; j <= r; j++) {
            if (a[j] < b[i+1]) {
                l = j;
            }
        }
        ans = 1ll * ans * (r - l) % mod;
    }
    pos = mp[b[m]];
    for (int i = pos; i <= n; i++) {
        if (a[i] < b[m]) {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
