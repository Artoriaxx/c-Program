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

const int N = 2e6 + 50;
const int p1 = 1e9 + 7;
const int p2 = 998244353;
int f1[N], f2[N];
int main() {
    int tc; in >> tc;
    f1[1] = f2[1] = 1, f1[2] = f2[2] = 2;
    for (int i = 3; i < N; i++) {
        f1[i] = (f1[i - 1] + f1[i - 2]) % p1;
        f2[i] = (f2[i - 1] + f2[i - 2]) % p2;
    }
    while (tc--) {
        int n, m, t;
        in >> n;
        int ans11 = 0, ans12 = 0;
        for (int i = 1; i <= n; i++) {
            int x; in >> x; 
            if (x) {
                ans11 = (ans11 + f1[i]) % p1;
                ans12 = (ans12 + f2[i]) % p2; 
            }
        } 
        in >> m;
        int ans21 = 0, ans22 = 0;
        for (int i = 1; i <= m; i++) {
            int x; in >> x; 
            if (x) {
                ans21 = (ans21 + f1[i]) % p1;
                ans22 = (ans22 + f2[i]) % p2; 
            }
        }
        int ans1 = 1ll * ans11 * ans21 % p1;
        int ans2 = 1ll * ans12 * ans22 % p2;
        in >> t;
        int ans31 = 0, ans32 = 0;
        for (int i = 1; i <= t; i++) {
            int x; in >> x; 
            if (x) {
                ans31 = (ans31 + f1[i]) % p1;
                ans32 = (ans32 + f2[i]) % p2; 
            }
        }
        for (int i = 1; i <= t; i++) {
            if ((ans31 + f1[i]) % p1 == ans1 && (ans32 + f2[i]) % p2 == ans2) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}