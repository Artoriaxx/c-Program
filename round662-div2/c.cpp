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
int a[N];
int b[N];
int cnt;
int pos[N];
int vis[N];
bool cmp(int x, int y) {
    return x > y;
}
int n; 

int main() {
    int t; in >> t;
    while (t--) {
        in >> n;
        for (int i = 1; i <= 1e5; i++) b[i] = 0, a[i] = 0;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x; in >> x;
            if (!a[x]) a[x] = ++cnt;
            b[a[x]]++;
        }
        int mx = 0, sze = 0;
        for (int i = 1; i <= cnt; i++) {
            if (b[i] > mx) {
                mx = b[i];
                sze = 1;
            } 
            else if (b[i] == mx) {
                sze++;
            }
        }
        printf("%d\n", (n - sze * mx) / (mx - 1) + sze - 1);
    }
    return 0;
}
