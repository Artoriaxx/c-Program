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

const int N = 505;
int a[N][N];
int sum[N][N], check[N][N];
int t[N*N*3];
int s[N];
ll ans = 0;
void calc(int a, int b, int x, int y) {
    s[x-1] = N * N;
    vector<int> tmp;
    for (int i = x; i <= y; i++) {
        s[i] = s[i-1] + sum[b-1][i] - sum[a][i];
        if (check[b][i] - check[a-1][i] == b - a + 1) {
            ans += t[s[i-1]] + t[s[i-1]+1] + t[s[i-1]-1];
            t[s[i]]++;
            tmp.push_back(s[i]);
        }
    }
    for (int e : tmp) t[e] = 0;
}
int main() {
    int n, m; in >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) in >> a[i][j];
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            sum[i][j] = sum[i-1][j] + (a[i][j] == 0 ? -1 : 1);//要加括号
            check[i][j] = check[i-1][j] + a[i][j]; 
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int l = 1;
            for (int k = 1; k <= m + 1; k++) {
                if (a[i][k] == 0 || a[j][k] == 0) {
                    if (k - l >= 2) calc(i, j, l, k - 1);
                    l = k + 1;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
