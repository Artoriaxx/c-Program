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

const int N = 2050;
int dp[N][N];
string mp[10] = {
    "1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"
};
string s[N];
int dif(string a, string b) {
    int num = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i] == '1' && b[i] == '0') return -1;
        else if (a[i] == '0' && b[i] == '1') num++;
    }
    return num;
}
int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= 9; j++) {
            int num = dif(s[i], mp[j]);
            if (num == -1) continue;
            else for (int K = 0; K <= k; K++) if (K >= num) dp[i][K] |= dp[i + 1][K - num];
        }
    }
    if (!dp[1][k]) puts("-1");
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 9; j >= 0; j--) {
                int num = dif(s[i], mp[j]);
                if (num != -1) {
                    if (dp[i + 1][k - num]) {
                        printf("%d", j);
                        k -= num;
                        break;
                    } 
                }
            }
        }
    } 
    return 0;
}
