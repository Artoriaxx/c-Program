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
const int p = 1e9 + 7;
int a[N];
int cnt[N][2];
int f[N];
int fac[N], inv[N];
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int C(int n, int m) {
    if (m > n) return 0;
    return 1ll * fac[n] * inv[n-m] % p * inv[m] % p;
}
int main() {
    fac[0] = inv[1] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i-1] * i % p;
    // for (int i = 2; i < N; i++) inv[i] = qpow(fac[i], p - 2);
    inv[N-1] = qpow(fac[N-1], p - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i+1] * (i + 1) % p;
    inv[0] = 1;
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int cnt1 = 0, cnt0 = 0;
        for (int i = 1; i <= n; i++) {
            in >> a[i]; a[i]--;
            if (a[i] & 1) cnt1++;
            else cnt0++;
            f[i] = i;
            cnt[i][a[i]] = 1;
            cnt[i][!a[i]] = 0;
        }
        int ans = (1ll * C(cnt1, 2) * cnt0 % p + C(cnt1, 3)) % p;
        printf("%d\n", ans);
        for (int i = 1; i < n; i++) {
            int u, v; in >> u >> v;
            u = find(u), v = find(v);
            int x = cnt[u][1], y = cnt[u][0];
            int z = cnt[v][1], w = cnt[v][0];
            if (u != v) {
                int tmp = 1ll * x * z % p * (n - x - z - y - w) % p;
                ans = (ans - tmp + p) % p;
                tmp = 1ll * x * w % p * (cnt1 - x - z) % p;
                ans = (ans - tmp + p) % p;
                tmp = 1ll * z * y % p * (cnt1 - x - z) % p;
                ans = (ans - tmp + p) % p;
                f[v] = u;
                cnt[u][1] += cnt[v][1];
                cnt[u][0] += cnt[v][0];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
