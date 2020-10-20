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

int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) in >> a[i];
        vector<int> ans1, ans0;
        for (int i = 1; i <= n; i++) {
            int ty; in >> ty;
            if (ty == 1) ans1.push_back(a[i]);
            else ans0.push_back(a[i]);
        }
        bool flag = true;
        if (ans1.size() == 0) {
            for (int i = 1; i < ans0.size(); i++) {
                if (ans0[i] < ans0[i - 1]) flag = false;
            }
            
        }
        else if (ans0.size() == 0) {
            for (int i = 1; i < ans1.size(); i++) {
                if (ans1[i] < ans1[i - 1]) flag = false;
            }
        }
        if (flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
