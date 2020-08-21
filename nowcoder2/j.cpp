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
int f[N], p[N];
int tot;
void euler(int n) {
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!f[i]) p[++tot] = i, f[i] = i - 1;
        for (int j = 1; j <= tot && i * p[j] <= n; j++) {
            if (i % p[j] == 0) {
                f[i * p[j]] = f[i] * p[j];
                break;
            }
            f[i * p[j]] = f[i] * (p[j] - 1);
        }
    }
}
int vis[N];
int qpow(int a, int b, int p) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return ans;
}
int ans[N];
int main() {
    int n, k; in >> n >> k;
    euler(n);
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        int j = i;
        vector<int> b;
        b.push_back(j);
        while (a[j] != i) {
            b.push_back(a[j]);
            j = a[j];
            vis[j] = 1;
        }
        int r = qpow(k % b.size(), f[b.size()] - 1, b.size());
        for (int i = 0; i < b.size(); i++) {
            ans[b[i]] = b[(i + r) % b.size()];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
