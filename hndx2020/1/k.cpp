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
int n, s, t;
ll ans[N];
void calc(int x) {
    multiset<int> st;
    for (int i = 1; i <= n; i++) st.insert(a[i]);
    int now = a[x];
    for (int i = 1; i <= n; i++) {
        multiset<int>::iterator it = st.lower_bound(now);
        if (it == st.end()) {
            it = st.lower_bound(0);
            ans[x] += s - now + *it;
        }
        else ans[x] += *it - now;
        ans[x] += t;
        now = (t + *it) % s;
        st.erase(it);
    }
}
ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}
int main() {
    
    in >> n >> s >> t;
    ll mn = 1e18, mx = 0;
    for (int i = 1; i <= n; i++) in >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        calc(i);
        mn = min(mn, ans[i]);
    }
    ll sum = 0;
    ans[n + 1] = ans[1]; a[n + 1] = a[1] + s;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i + 1] - a[i] - 1 + ans[i + 1]);
        sum += (ans[i + 1] + a[i + 1] - a[i] - 1 + ans[i + 1]) * (a[i + 1] - a[i]) / 2;
    }
    ll g = gcd(sum, s);
    printf("%lld\n%lld\n%lld/%lld\n", mn, mx, sum / g, s / g);
    return 0;
}
