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

const int N = 10050;
int a[N];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort (a + 1, a + n + 1);
        int now = 0, ans = 0;
        int i = 1;
        while (i <= n) {
            int x = a[i] - now;
            int cnt = (x - 1) / 2 + 1;
            ans += cnt;
            now += cnt * 2;
            while (a[i] - now <= 0 && i <= n) {
                while (a[i] - now <= 0 && i <= n) i++;
                now += 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
