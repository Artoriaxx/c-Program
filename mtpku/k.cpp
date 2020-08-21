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

const int N = 6e5 + 50;
char s[N];
int main() {
    int t; scanf("%d", &t);
    getchar();
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        set<int> st[10];
        for (int i = 0; i < 10; i++) st[i].clear();
        for (int i = 1; i <= len; i++) {
            st[s[i] - '0'].insert(i);
        }
        for (int i = 1; i <= len / 6; i++) {
            int now = 0;
            auto it = st[1].upper_bound(now);
            now = *it;
            st[1].erase(it);
            printf("%d ", now);
            it = st[1].upper_bound(now);
            now = *it;
            st[1].erase(it);
            printf("%d ", now);
            it = st[4].upper_bound(now);
            now = *it;
            st[4].erase(it);
            printf("%d ", now);
            it = st[5].upper_bound(now);
            now = *it;
            st[5].erase(it);
            printf("%d ", now);
            it = st[1].upper_bound(now);
            now = *it;
            st[1].erase(it);
            printf("%d ", now);
            it = st[4].upper_bound(now);
            now = *it;
            st[4].erase(it);
            printf("%d\n", now);
        }
    }
    return 0;
}
