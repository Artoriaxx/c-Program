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
int main() {
    int t; in >> t;
    while (t--) {
        int n, x; in >> n >> x;
        for (int i = 1; i <= n; i++) {
            in >> a[i];
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] & 1) cnt1++;
            else cnt2++;
        }
        if (x % 2 == 0) {
            
            bool flag = false;
            for (int i = 0; i <= cnt1; i++) {
                if (flag) break;
                for (int j = 0; j <= cnt2; j++) {
                    if ((i & 1) && (j & 1) && i + j == x) {
                        puts("Yes");
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) puts("No");
        }
        else {
            bool flag = false;
            for (int i = 0; i <= cnt1; i++) {
                if (flag) break;
                for (int j = 0; j <= cnt2; j++) {
                    if ((i & 1) && (j % 2 == 0) && i + j == x) {
                        puts("Yes");
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) puts("No");
        }

    }
    return 0;
}
