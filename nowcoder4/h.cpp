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
int vis[N];
int prime[N];
int notprime[N];
int main() {
    int tot = 0;
    int nn = 2e5 + 20;
    for (int i = 2; i <= nn; i++) {
        if (!notprime[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= nn; j++) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        memset(vis, 0, sizeof(vis));
        vector<int> a, b;
        for (int i = n; i >= 2; i--) {
            if (vis[i]) continue;
            if (notprime[i]) continue;
            vector<int> s;
            s.clear();
            for (int j = 1; j * i <= n; j++) {
                if (!vis[j * i]) s.push_back(j * i);
            }
            if (s.size() == 1) continue;
            if (s.size() & 1) {
                int cnt = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == 1) {
                        continue;
                    }
                    cnt++;
                    if (cnt & 1) a.push_back(s[i]);
                    else b.push_back(s[i]);
                    vis[s[i]] = 1;
                }
            }
            else {
                for (int i = 0; i < s.size(); i++) {
                    if (i & 1) a.push_back(s[i]);
                    else b.push_back(s[i]);
                    vis[s[i]] = 1;
                }
            }
        }
        printf("%d\n", a.size());
        for (int i = 0; i < a.size(); i++) {
            printf("%d %d\n", a[i], b[i]);
        }
    }
    return 0;
}
