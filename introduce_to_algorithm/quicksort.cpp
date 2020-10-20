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
int Partition(int a[], int p, int r)
{
    int i = p, j = r+1;
    int x = a[p];
    while(true)
    {
        while(a[++i] < x);
        while(a[--j] > x);
        if(i >= j) break;
 
        int t;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}
int main() {
    int n; in >> n; for (int i = 1; i <= n; i++) in >> a[i];
    Partition(a, 1, n);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}
