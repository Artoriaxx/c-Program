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
int n, k; 
int a[N];
bool check(int x) {
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (len % 2 == 0) len++;
        else {
            if (a[i] <= x) len++;
        }
    }
    int len1 = 0;
    for (int i = 1; i <= n; i++) {
        if (len1 & 1) len1++;
        else {
            if (a[i] <= x) len1++;
        }
    }
    return max(len1, len) >= k;
    
}
int main() {
    in >> n >> k;
    for (int i = 1; i <= n; i++) in >> a[i];
    int l = 1, r = 1e9 + 50;
    int ans = r;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = min(ans, mid), r = mid - 1;
        else l = mid + 1;
    } 
    printf("%d\n", ans);
    return 0;
}
