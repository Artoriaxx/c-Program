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
char s[N];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ans = 1e9;
        for (int i = 0; i <= len; i++) {
            int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
            for (int k = 1; k <= len; k++) {
                if (s[k] != '0') ans1++;
                if (s[k] != '1') ans2++;
                if (k <= i && s[k] != '0') ans3++;
                if (k > i && s[k] != '1' ) ans3++;
                if (k <= i && s[k] != '1') ans4++;
                if (k > i && s[k] != '0' ) ans4++;
            }
            ans = min(ans, ans1);
            ans = min(ans, ans2);
            ans = min(ans, ans3);
            ans = min(ans, ans4);
        }
        printf("%d\n", ans);
    }
    return 0;
}
