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

const int N = 1050;
vector<int> num[N];
int a[N];
int ans[N];
int main() {
    int n, k; in >> n >> k;
    for (int i = 1; i <= n; i++) {
        in >> a[i];
        if (a[i] == -1) num[0].push_back(i);
        else num[a[i]].push_back(i);
    }
    for (int i = 1; i <= k; i++) {
        int mn = 1e9, mx = 0, pos1 = 0, pos2 = 0;
        for (int j = 0; j <= k; j++) {
            if (num[j].size() > 0 && num[j].size() < mn) {
                mn = num[j].size();
                pos1 = j;
            }
            if (num[j].size() > 0 && num[j].size() >= mx) {
                mx  = num[j].size();
                pos2 = j;
            }
        }
        if (mn + mx < n / k) {
            puts("No");
            return 0;
        }
        int x = min((int)num[pos1].size(), n / k);
        for (int j = 0; j < x; j++) {
            ans[num[pos1].back()] = pos2;
            num[pos1].pop_back();
        }
        for (int j = 0; j < n / k - x; j++) {
            ans[num[pos2].back()] = pos1;
            num[pos2].pop_back();
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) a[i] = 1;
        if (ans[i] == 0) ans[i] = 1;
        printf("%d %d\n", a[i], ans[i]);
    }
    return 0;
}
