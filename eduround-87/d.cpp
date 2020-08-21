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
int d[N];
int n, q;
inline void update(int x, int v) {
    for (int i = x; i <= n; i += i & (-i)) d[i] += v;
}
int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & (-i)) ans += d[i];
    return ans;
}
inline int findk(int k) {
    int ans = 0, cnt = 0;
    for (int i = 20; i >= 0; i--) {
        ans += (1 << i);
        if (ans > n || cnt + d[ans] >= k) ans -= (1 << i);
        else cnt += d[ans];
    }
    return ans + 1;
}
int main() {
    //freopen("1.txt", "r", stdin);
    in >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; in >> x;
        update(x, 1);
    }
    for (int i = 1; i <= q; i++) {
        
        int k;
        in >> k;
        if (k >= 1) update(k, 1);
        else {
            k = -k;
            // int l = 1, r = n;
            // while (l <= r) {
            //     int mid = (l + r) >> 1;
            //     if (query(mid) >= k) {
            //         r = mid - 1;
            //     }
            //     else l = mid + 1;
            // }
            int l = findk(k);
            update(l, -1);
        }
    }
    int ans = findk(1);
    if (ans == n + 1) ans = 0;
    printf("%d\n", ans);
    // for (int i = 1; i <= n; i++) {
    //     if (query(i) - query(i - 1) > 0) {
    //         printf("%d\n", i);
    //         return 0;
    //     }
    // }
    // puts("0");
    return 0;
}
