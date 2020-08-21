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
int a[N], c[N];
vector<int> b[N];
struct node {
    int now, id;
    bool operator < (const node &b) const {
        return now > b.now;
    }
};
int main() {
    int n, k; in >> n >> k;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= k; i++) in >> c[i];
    sort(a + 1, a + n + 1);
    priority_queue<node> q;
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (q.empty() || q.top().now >= c[a[i]]) {
            b[++cnt].push_back(a[i]);
            node x;
            x.now = 1;
            x.id = cnt;
            q.push(x);
        }
        else {
            node x = q.top(); q.pop();
            b[x.id].push_back(a[i]);
            x.now++;
            q.push(x);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%d", b[i].size());
        for (int j = 0; j < b[i].size(); j++) {
            printf(" %d", b[i][j]);
        }
        puts("");
    }
    
    return 0;
}
