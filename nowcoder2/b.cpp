#include <bits/stdc++.h>
#define pdd pair<double, double>
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
const double eps = 1e-8;
int x[N], y[N];
template <typename T> T cross(T a, T b, T c, T d) {
    return a * d - b * c;
}
bool check(pdd a, pdd b) {
    if (fabs(a.first - b.first) > eps) return false;
    if (fabs(a.second - b.second) > eps) return false;
    return true;
}
int main() {
    int n; in >> n;
    for (int i = 1; i <= n; i++) in >> x[i] >> y[i];
    
    int mx = 0;
    vector<pdd> s;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[i] * y[j] - x[j] * y[i] == 0) continue;
            ll a11 = 2 * x[i], a12 = 2 * y[i], a13 = x[i] * x[i] + y[i] * y[i];
            ll a21 = 2 * x[j], a22 = 2 * y[j], a23 = x[j] * x[j] + y[j] * y[j];
            ll d0 = cross(a11, a12, a21, a22);
            ll d1 = cross(a13, a12, a23, a22);
            ll d2 = cross(a11, a13, a21, a23);
            s.push_back(pdd((double)d1 / d0, (double)d2 / d0));
        }
    }
    sort(s.begin(), s.end());
    int now = 1;
    for (int i = 1; i < s.size(); i++) {
        if (check(s[i], s[i - 1])) now++;
        else now = 1;
        mx = max(mx, now);
    }
    for (int i = 1; i <= 2000; i++) {
        if ((i - 1) * i / 2 == mx) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}