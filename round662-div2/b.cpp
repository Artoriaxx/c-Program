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
int num[N];
int main() {
    int n; scanf("%d", &n);
    set<int> s8, s6, s4, s2;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        num[a[i]]++;
        if (num[a[i]] >= 8) {
            s8.insert(a[i]);
            s6.erase(a[i]);
        }
        else if (num[a[i]] >= 6) {
            s6.insert(a[i]);
            s4.erase(a[i]);
        }
        else if (num[a[i]] >= 4) {
            s2.erase(a[i]);
            s4.insert(a[i]);
        }
        else if (num[a[i]] >= 2) {
            s2.insert(a[i]);
        }
    }
    
    int q; scanf("%d", &q);
    while (q--) {
        char ch[2]; int x;
        scanf("%s%d", ch, &x);
        if (ch[0] == '+') {
            num[x]++;
            if (num[x] >= 8) {
                s8.insert(x);
                s6.erase(x);
            }
            else if (num[x] >= 6) {
                s6.insert(x);
                s4.erase(x);
            }
            else if (num[x] >= 4) {
                s2.erase(x);
                s4.insert(x);
            }
            else if (num[x] >= 2) {
                s2.insert(x);
            }
        }
        else {
            num[x]--;
            if (num[x] == 7) {
                s8.erase(x);
                s6.insert(x);
            }
            else if (num[x] == 5) {
                s6.erase(x);
                s4.insert(x);
            }
            else if (num[x] == 3) {
                s4.erase(x);
                s2.insert(x);
            }
            else if (num[x] == 1) {
                s2.erase(x);
            }
        }
        if (s8.size() > 0) {
            puts("YES");
        }
        else if (s4.size() > 1) {
            puts("YES");
        }
        else if (s4.size() > 0 && s2.size() > 1) {
            puts("YES");
        }
        else if (s6.size() > 0 && s2.size() > 0) {
            puts("YES");
        }
        else if (s6.size() > 0 && s4.size() > 0) {
            puts("YES");
        }
        else if (s6.size() > 1) {
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
