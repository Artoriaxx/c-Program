#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 5050;
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
struct node {
    int u, l;
    bool operator < (const node &b) const {
        return u == b.u ? l < b.l : u < b.u;
    }
} a[N];
int ans[N];
int n, m, X1, Y1, X2, Y2, px, py;
struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
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
};
typedef point vect;
int check(int x) {
    vect line1 = vect(a[x].u - a[x].l, Y1 - Y2);
    vect line2 = vect(px - a[x].l, py - Y2);
    double res = line1 ^ line2;
    return sgn(line1 ^ line2);
}
int ans1[N];
int main() {
    while (scanf("%d", &n) && n) {
        memset(ans, 0, sizeof(ans));
        memset(ans1, 0, sizeof(ans1));
        scanf("%d%d%d%d%d", &m, &X1, &Y1, &X2, &Y2);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].u, &a[i].l);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &px, &py);
            int l = 1, r = n;
            int res;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (check(mid) == 1) {
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ans[l - 1]++;
        }
        for (int i = 0; i <= n; i++) {
            ans1[ans[i]]++;
        }
        printf("Box\n");
        for (int i = 1; i <= m; i++) {
            if (ans1[i]) {
                printf("%d: %d\n", i, ans1[i]);
            }
        }
    }
    return 0;
}