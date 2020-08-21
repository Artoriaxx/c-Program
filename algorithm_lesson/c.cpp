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
bool check(int x) {
    return (x % 400 == 0) || (x % 4 == 0 && x % 100 != 0);
}
int num[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[10];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i <= 6; i++) ans[i] = 0;
        int now = 0;
        for (int i = 1900; i <= 1900 + n - 1; i++) {
            if (check(i)) num[2] = 29;
            else num[2] = 28;
            for (int j = 1; j <= 12; j++) {
                ans[(now + 13) % 7]++;
                now += num[j];
            }
        }
        printf("%d ", ans[6]);
        for (int i = 0; i < 6; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}
