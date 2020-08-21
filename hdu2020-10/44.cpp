#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct READ {
    inline char read() {
    #ifdef _WIN32
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

const int N = 5050;
const ll modd = 1e9 + 7;
ll dp[N][N];
ll c[N][N];
int a[N];
int main() {
    for(int i=0;i<=5000;i++)c[i][0]=1;
	for(int i=1;i<=5000;i++)for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%modd;
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 1; i < n; i++) in >> a[i];
        a[0] = a[n] = -1;
        
        
        
    }
    return 0;
}
