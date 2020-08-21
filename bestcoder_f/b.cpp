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
char tmp[N];
int s[N], t[N];
int s1[N];
int sum1[N], sum2[N];
int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int n; scanf("%d", &n);
        scanf("%s", tmp);
        s[n] = t[n] = 0;
        for (int i = 0; i <= n; i++) sum1[i] = sum2[i] = 0;
        for (int i = 0; i < n; i++) s[i] = tmp[i] - '0';
        scanf("%s", tmp);
        for (int i = 0; i < n; i++) t[i] = tmp[i] - '0';
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) sum1[i]++;
            if (t[i] != 0) sum2[i]++;
        }
        for (int i = 1; i < n; i++) {
            sum1[i] += sum1[i - 1];
            sum2[i] += sum2[i - 1];
        }
        int ans = sum1[n - 1];
        int now = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n) {
                ans = min(ans, now + 1 + sum2[n - 1] + 1);
                break;
            }
            if (i == 0) {
                if (s[i] != 1) now++;
                continue;
            }
            if (s[i] != 0) 
                ans = min(ans, now + sum2[i - 1] + 1 + (t[i] == 0) + sum1[n - 1] - sum1[i] + 1);
            else 
                ans = min(ans, now + sum2[i - 1] + (t[i] == 0) + sum1[n - 1] - sum1[i] + 1);
            if (s[i] != 1) now++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
