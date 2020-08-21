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

const int N = 5e6 + 50;
struct node {
    ll x, y;
    bool operator == (const node &b) const {
        return x == b.x && y == b.y;
    }
    bool operator < (const node &b) const {
        if (x == b.x) return y < b.y;
        else return x < b.x;
    }
};
ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll d[N];
map<int, int> e[N];
int main() {
    int t; in >> t;
    while (t--) {
        node p;
        in >> p.x >> p.y;
        queue<node> q;
        while (!q.empty()) q.pop();
        q.push(p);
        map<node, int> mp;
        mp.clear();
        int cnt = 0;
        mp[p] = ++cnt;
        bool flag = true;
        while (!q.empty()) {
            node now = q.front(); q.pop();
            if (now.x == now.y) {
                flag = false;
                break;
            }
            for (int i = 0; i < 8; i++) {
                node nx;
                nx.x = now.x + dx[i];
                nx.y = now.y + dy[i];
                if (gcd(nx.x, nx.y) > 1) {
                    if (!mp[nx]) {
                        mp[nx] = ++cnt;
                        d[mp[now]]++;
                        d[mp[nx]]++;
                        e[mp[now]][mp[nx]] = 1;
                        e[mp[nx]][mp[now]] = 1;
                        q.push(nx);
                    }
                    else if (!e[mp[now]].count(mp[nx])) {
                        e[mp[now]][mp[nx]] = 1;
                        e[mp[nx]][mp[now]] = 1;
                        d[mp[nx]]++;
                        d[mp[now]]++;
                    }
                }
            }
        }
        if (!flag) {
            puts("0/1");
            for (int i = 1; i <= cnt; i++) d[i] = 0, e[i].clear();
            continue;
        }
        ll ans1 = d[1] + 1;
        ll ans2 = 0;
        for (int i = 1; i <= cnt; i++) {
            ans2 += d[i] + 1;
        }
        ll g = gcd(ans1, ans2);
        ans1 /= g;
        ans2 /= g;
        printf("%lld/%lld\n", ans1, ans2);
        for (int i = 1; i <= cnt; i++) d[i] = 0, e[i].clear();
    }
    return 0;
}
