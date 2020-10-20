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
int a[N];
int vis[N];
int main() {
    int n; in >> n;
    for (int i = 1; i <= n; i++) in >> a[i];
    set<int> mex;
    for (int i = 0; i <= n; i++) {
        if (i != a[n]) {
            mex.insert(i);
        }
    }
    vector<int> ans;
    for (int i = n - 1; i >= 1; i--) {
        auto it = mex.lower_bound(a[i]);
        ans.push_back(*it);
        mex.erase(it);
    }
    ans.push_back(*mex.begin());
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}
