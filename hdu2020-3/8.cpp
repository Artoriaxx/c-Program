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

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    Point rotate(Point p, double angle) {
        Point v = Point(x - p.x, y - p.y);
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};
const double pi = acos(-1.0);
int l, x, y, vx, vy, k;
bool calc(double t) {
    double tx = t * vx + x;
    double ty = t * vy + y;
    ll tot = 0;
    double d = sqrt(3) * l / 2.0;
    tot += abs(floor(ty / d));
    Point ed = Point(tx, ty);
    Point center = Point(0, d / 3);
    Point t1 = ed.rotate(center, 120.0 / 180.0 * pi);
    tot += abs(floor(t1.y / d));
    t1 = ed.rotate(center, 240.0 / 180.0 * pi);
    tot += abs(floor(t1.y / d));
    return tot < k;
}
int main() {
    int t; in >> t;
    while (t--) {
        in >> l >> x >> y >> vx >> vy >> k;
        int tt = 100;
        double l = 0, r = 1e10;
        while (tt--) {
            double mid = (l + r) / 2;
            if (calc(mid)) l = mid;
            else r = mid;
        }
        printf("%.10f\n", (l + r) / 2);
    }
    return 0;
}
