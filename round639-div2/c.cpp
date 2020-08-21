#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct READ {
    inline char read() {
    #ifdef _WIN32
        return getchar();
    #endif
        static const int IN_LEN = 1 << 18 | 1;
        static char buf[IN_LEN], *s, *t;
        return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)), s == t ? -1 : *s++;
    }
    template <typename _Tp> inline READ & operator >> (_Tp&x) {
        static char c11, boo;
        for(c11 = read(),boo = 0; !isdigit(c11); c11 = read()) {
            if(c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for(x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
} in;

const int N = 2e5 + 50;
int mod(int a, int b) {
    int x = a % b;
    return x < 0 ? x + b : x;
}
int a[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        for (int i = 0; i < n; i++) in >> a[i];
        bool flag = false;
        map<int, int> mp;
        mp.clear();
        for (int i = 0; i < n; i++) {
            int x = mod(i, n);
            int y = mod(i + a[x], n);
            if (mp.count(y)) flag = true;      
            else mp[y] = 1;
        }
        if (!flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
