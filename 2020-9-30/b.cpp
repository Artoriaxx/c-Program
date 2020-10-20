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

const int N = 1e5 + 50;
const int p = 1e9 + 7;
string s[N];
struct node {
    int a[N];
    int p;
    bool operator < (const node &b) const {
        if (a[0] == b.a[0]) {
            for (int i = N - 2; i >= 1; i--) {
                //printf("%d ", i);
                if (a[i] == b.a[i]) continue;
                return a[i] < b.a[i];
            }
            return 0;
        }
        else return a[0] < b.a[0];
    }
} w[30];
int c[30];
int vis[30];
int main() {
    int n, cse = 0;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 0; i < 26; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) {
            int len = s[i].length();
            vis[s[i][0] - 'a'] = 1;
            for (int j = 0; j < len; j++) {
                w[s[i][j] - 'a'].a[len - j]++;
                w[s[i][j] - 'a'].a[0] = max(w[s[i][j] - 'a'].a[0], len - j);
            }
        }
        for (int i = 0; i < 26; i++) {
            int len = w[i].a[0] + 10;
            for (int j = 1; j <= len; j++) {
                w[i].a[j + 1] += w[i].a[j] / 26;
                w[i].a[j] %= 26;
                if (w[i].a[j] > 0) w[i].a[0] = j;
            }
            w[i].p = i;
        }
        // for (int i = 0; i < 10; i++) printf("%d ", w[0].a[i]);
        // puts("");
        sort(w, w + 26);
        int pos = 0;
        for (int i = 0; i < 26; i++) {
            if (!vis[w[i].p]) {
                c[w[i].p] = 0;
                pos = i;
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (i == pos) continue;
            if (i < pos) c[w[i].p] = i + 1;
            else c[w[i].p] = i;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int len = s[i].length();
            int base = 1;
            for (int j = len - 1; j >= 0; j--) {
                ans = (ans + 1ll * base * c[s[i][j] - 'a'] % p) % p;
                base = 1ll * base * 26 % p;
            }
        }
        printf("Case #%d: %d\n", ++cse, ans);
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= w[i].a[0]; j++) {
                w[i].a[j] = 0;
            }
            w[i].a[0] = 0;
        }
    }
    return 0;
}
