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
int a[N], k[N];
int n, q;
bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (a[i] <= x) cnt++;
    for (int i = 1; i <= q; i++) {
        if (k[i] < 0 && -k[i] <= cnt) cnt--;
        if (k[i] > 0 && k[i] <= x) cnt++;
    } 
    return cnt > 0;
}
int main() {
    in >> n >> q;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= q; i++) in >> k[i];
    if (!check(1e9)) {
        puts("0");
        return 0;
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
