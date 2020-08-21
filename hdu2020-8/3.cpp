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
struct point {
    ll x, y;
};
ll cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int t; in >> t;
    while (t--) {
        point p1, p2, p3;
        in >> p1.x >> p1.y;
        in >> p2.x >> p2.y;
        in >> p3.x >> p3.y;
        ll a = cross(p1, p2), b = cross(p2, p3), c = cross(p3, p1);
        int cnt1 = 0, cnt2 = 0;
        if (a < 0) cnt1++;
        if (b < 0) cnt1++;
        if (cross(p1, p2) < 0 || cross(p2, p3) < 0) puts("Clockwise");
        else puts("Counterclockwise");
    }
    return 0;
}
