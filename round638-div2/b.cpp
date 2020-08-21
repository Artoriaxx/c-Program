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
int vis[N];
int main() {
    int t; in >> t;
    while (t--) {
        int n, k; in >> n >> k;
        for (int i = 1; i <= n; i++) in >> a[i];
        for (int i = 1; i <= n; i++) vis[i] = 0;
        vector<int> li;
        for (int i = 1; i <= n; i++) {
            if (!vis[a[i]]) li.push_back(a[i]), vis[a[i]] = 1;
        }
        if (li.size() > k) puts("-1");
        else {
            if (li.size() < k) {
                for (int i = 1; i <= n; i++) {
                    if (li.size() < k) {
                        if (!vis[i]) li.push_back(i);
                    }
                    else break;
                }
            }
            printf("%d\n", n * k);
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < k; j++) {
                    printf("%d ", li[j]);
                    cnt++;
                }
            }
            puts("");
        }
    }
    return 0;
}
