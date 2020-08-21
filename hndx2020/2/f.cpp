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
double dd(int ax, int ay, int bx, int by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}
int main() {
    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    int d, v;
    scanf("%d%d", &d, &v);
    int dth, dtm, th, tm;
    scanf("%d:%d%d:%d", &dth, &dtm, &th, &tm);
    int w;
    scanf("%d", &w);
    double dis1 = dd(ax, ay, cx, cy);
    double dis2 = dd(cx, cy, bx, by);
    double dis3 = dd(ax, ay, bx, by);
    double ans1 = 1.0 * dis1 * 60.0 / v + 1.0 * dis2 * 60.0 / v;
    ans1 += d;
    th = dth + th;
    tm = dtm + tm;
    double ans2 = (th - 9) * 60 + tm;
    double ans3 = 1.0 * dis3 * 60 / w;
    if ((by - ay) * (cx - ax) == (cy - ay) * (bx - ax)) ans3 += d;
    if (ans1 < ans2 && ans1 < ans3) {
        puts("Alex");
    }
    else if (ans2 < ans1 && ans2 < ans3) {
        puts("Dmitry");
    }
    else {
        puts("Petr");
    }
    return 0;
}
