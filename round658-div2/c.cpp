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
 
const int N = 100050;
char a[N], b[N];
void change(char &c) {
    if (c == '1') c = '0';
    else c = '1';
}
char get(char c, int cnt) {
    if (cnt % 2 == 0) return c;
    else {
        if (c == '1') return '0';
        else return '1';
    }
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        scanf("%s%s", a + 1, b + 1);
        vector<int> ans;
        int l = 1, r = n;
        int cnt = 0;
        for (int i = n; i >= 1; i--) {
            if (get(a[r], cnt) != b[i]) {
                if (get(a[l], cnt) == b[i]) {
                    ans.push_back(1);
                    change(a[l]);
                }
                ans.push_back(i);
                swap(l, r);
                cnt++;
            }
            if (l > r) r++;
            else r--;
        }
        printf("%d", ans.size());
        for (auto x : ans) {
            printf(" %d", x);
        }
        puts("");
    }
    return 0;
}