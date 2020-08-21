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

const int N = 1e6 + 50;
const int mod = 1e9 + 9;
const int CC = 276601605;
const int A = 691504013;
const int invA = 691504012;
const int B = 308495997;
int fac[N], inv[N];
inline int qpow(int a, ll b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init() {
    fac[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i-1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
}

int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
 
int main() {
    init();
    int t; in >> t;
    while (t--) {
        ll n, c; int k; in >> n >> c >> k;
        int change = 1ll * qpow(invA, c) * qpow(B, c) % mod;
        int q = qpow(qpow(A, c), k);
        //printf("%d %d\n", change, q);
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            int d = C(k, i);
            if (i & 1) d = mod - d;
            if (q == 1) ans = (ans + 1ll * d * (n % mod) % mod);
            else ans = (ans + 1ll * d * q % mod * (qpow(q, n % (mod - 1)) - 1 + mod) % mod * qpow(q - 1, mod - 2) % mod) % mod;
            //从第0项开始和1项开始均可，%(mod-1)为欧拉定理的应用，a^f(n)同余1，f(n)为欧拉函数
            //mod为质数，f(n)=mod-1
            //a^n=a^(k*(1e9+8)+r)=a^(k*(1e9+8)) * a^r=1*a^r
            q = 1ll * q * change % mod;
        }
        printf("%lld\n", 1ll * ans * qpow(CC, k) % mod);
    }
    return 0;
}