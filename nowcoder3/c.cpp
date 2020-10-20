#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 50;
const db eps = 1e-5;
int sgn(db x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
struct point {
    db x, y;
    void read() { scanf("%lf%lf", &x, &y); }
    db operator ^ (const point &b) const {
        return x * b.y - y * b.x;
    }
    db dis(point b) {
        return hypot(x - b.x, y - b.y);
    }
} p[25];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 20; i++) p[i].read();
        p[20] = p[0];
        db s = 0;
        for (int i = 0; i < 20; i++) s += p[i] ^ p[i + 1];
        if (s < 0) reverse(p, p + 20);
        p[20] = p[0], p[21] = p[1];
        for (int i = 0; i < 20; i++) {
            if (sgn(p[i].dis(p[i+1]) - 9) == 0) {
                if (sgn(p[i+1].dis(p[i+2]) - 8) == 0) puts("right");
                else puts("left");
            } 
        }
    }
    return 0;
}
