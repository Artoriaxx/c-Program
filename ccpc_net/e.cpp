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

const int N = 50;
unordered_map<int, int> sg;
int Sgg(int n) {
    if (n == 1) return 0;
    if (n == 2) return sg[2] = 1;
    if (sg.count(n)) return sg[n];
    bool vis[N] = {0};
    vis[0] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int x = n / i;
        if (x & 1) {
            
            int z = Sgg(i);
            vis[z] = 1;
            
        }
        if (i * i == n || i == 1) continue;
        x = i;
        if (x & 1) vis[Sgg(n / i)] = 1;
    }
    for (int i = 0; ; i++) {
        if (!vis[i]) {
            sg[n] = i;
            return i;
        }
    }
}
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; in >> x;
            int y = Sgg(x);
            ans ^= y;
        }
        if (ans) puts("W");
        else puts("L");
    }
    return 0;
}
/*
10
10
999994815
1000000000 999999999 999999998 999999997 999999996 999999995 999999994 999999993 999999992 999999991 
*/
