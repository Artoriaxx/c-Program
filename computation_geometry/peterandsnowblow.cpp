#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
double mysqrt(double x) {
    return sqrt(max(x, 0.0));
}
struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    bool operator == (const point &b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.x) == 0;
    }
    bool operator < (const point &b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : sgn(x - b.x) < 0;
    }
    //向量+
    point operator + (const point &b) const {
        return point(x + b.x, y + b.y);
    }
    //向量-
    point operator - (const point &b) const  {
        return point(x - b.x, y - b.y);
    }
    //数乘向量
    point operator * (const double &k) const {
        return point(x * k, y * k);
    }
    //数除向量
    point operator / (const double &k) const {
        return point (x / k, y / k);
    }
    //叉积
    double operator ^ (const point &b) const {
        return x * b.y - y * b.x;
    }
    //点积
    double operator * (const point &b) const {
        return x * b.x + y * b.y;
    }
    //两点间距离
    double dist(point b) {
        return hypot(x - b.x, y - b.y);
    }
    //计算pa和pb的夹角,lightoj1203
    double rad(point a, point b) {
        point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    //化为长度为r的向量
    point trunc(double r) {
        double l = hypot(x, y);
        if (!sgn(l)) return *this;
        r /= l;
        return point(x * r, y * r);
    }
    //逆时针旋转90度
    point rotleft() {
        return point(-y, x);
    }
    //顺时针旋转90度
    point rotright() {
        return point(y, -x);
    }
    //绕着p点逆时针旋转angle度
    point rotate(point p, double angle) {
        point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
};
struct line {
    point s, e;
    line() {}
    line(point s, point e): s(s), e(e) {}
    bool operator == (const line &v) {
        return (s == v.s) && (e == v.e);
    }
    //根据一个点和倾斜角angle确定直线
    line (point p, double angle) {
        s = p;
        if (sgn(angle - pi / 2) == 0) {
            e = (s + point(0 , 1));
        }
        else {
            e = (s + point(1, tan(angle)));
        }
    }
    //ax + by + c = 0
    line(double a, double b, double c) {
        if (sgn(a) == 0) {
            s = point(0, -c / b);
            e = point(1, -c / b);
        }
        else if (sgn(b) == 0) {
            s = point(-c / a, 0);
            e = point(-c / a, 1);
        }
        else {
            s = point(0, -c / b);
            e = point(1, (-c - a) / b);
        }
    }
    void adjust() {
        if (e < s) swap(s, e);
    }
    //求线段长度
    double length() {
        return s.dist(e);
    }
    //返回直线倾斜角 0<=angle<pi
    double angle() {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    //点和直线关系
    //1 在左侧
    //2 在右侧
    //3 在直线上
    int relation(point p) {
        int c = sgn((p - s) ^ (e - s)) 
        if (c < 0) return 1;
        else if (c > 0) return 2;
        else return 3;
    }
    //点在线段上的判断
    bool pointonseg(point p) {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    //两向量平行
    bool parallel(line v) {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    
    //点到直线距离
    double dispointtoline(point p) {
        return fabs((p - s) ^ (e - s)) / length();
    }
    //点到线段距离
    double dispointtoseg(point p) {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e) < 0))
            return min(p.dist(s), p.dist(e));
        return dispointtoline(p);
    }
};
const int N = 1e5 + 10;
point pp[N];
int main() {
    int n;
    point p;
    scanf("%d", &n);
    p.input();
    double minn = inf, maxx = 0;
    for (int i = 1; i <= n; i++) {
        pp[i].input();
    }
    for (int i = 1; i <= n; i++) {
        maxx = max(p.dist(pp[i]), maxx);
        int j = i == n ? 1 : i + 1;
        line line1 = line(pp[i], pp[j]);
        minn = min(minn, line1.dispointtoseg(p));
    }
    printf("%lf\n", pi * (maxx * maxx - minn * minn));
    return 0;
}