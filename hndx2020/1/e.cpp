#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 50;
double n, p, s, v;
double calc(double x) {
    double ans1 = n * pow(log(n) / log(2.0), x * sqrt(2.0)) / (p * 1e9);
    ans1 += s * (1.0 + 1.0 / x) / v;
    return ans1;
}
int main() {
    scanf("%lf%lf%lf%lf", &n, &p, &s, &v);
    double l = 0, r = 100;
    int t = 100;
    double ans = 1e60, c;
    while (t--) {
        double midl = (l + r) / 2;
        double midr = (midl + r) / 2;
        double ans1 = calc(midl), ans2 = calc(midr);
        if (ans1 > ans2) {
            l = midl;
            if (ans > ans2) {
                ans = ans2;
                c = midr;
            }
        }
        else {
            r = midr;
            if (ans > ans1) {
                ans = ans1;
                c = midl;
            }
        }
    }
    printf("%.7f %.7f\n", ans, c);
    return 0;
}
