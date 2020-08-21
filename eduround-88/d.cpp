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
int pre[N];
int st[N][20], lg2[N];
void ST(int n) {
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; (i + (1 << j) - 1) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
}
int rmq(int l, int r) {
    if (l > r) return 0;
    else {
        int x = lg2[r - l + 1];
        return max(st[l][x], st[r - (1 << x) + 1][x]);
    }
}
#define pii pair<int, int>
int main() {
    int n; in >> n;
    for (int i = 1; i <= n; i++) {
        in >> a[i];
    }
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    ST(n);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        q.push(pii(pre[i], i));
        int cnt = 61;
        vector<pii> tmp;
        while (!q.empty() && cnt) {
            cnt--;
            tmp.push_back(q.top());
            q.pop();
        }
        for (auto e : tmp) {
            int r = e.second;
            int mx = rmq(i, r);
            ans = max(ans, e.first - pre[i - 1] - mx);
        }
        for (auto e : tmp) {
            q.push(e);
        }
    }
    printf("%d\n", ans);
    return 0;
}
