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
char a[N], b[N];
int f[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s%s", &n, a + 1, b + 1);
        vector<int> vb[21];
        for (int i = 1; i <= n; i++) {
            vb[b[i] - 'a'].push_back(a[i] - 'a');
        }
        for (int i = 0; i < 21; i++) f[i] = i;
        bool flag = true;
        int ans = 0;
        for (int i = 0; i < 20; i++) {
            for (int e : vb[i]) {
                int x = find(e);
                if (x > i) {
                    flag = false;
                    break;
                } 
                if (x < i) {
                    int y = find(i);
                    f[x] = y;
                    ans++;
                }
            }
        }
        if (!flag) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}
