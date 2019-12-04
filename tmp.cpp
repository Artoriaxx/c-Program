#include <bits/stdc++.h>
using namespace std;
double x[15], f[15];
int main() {
    // for (int i = 1; i <= 10; i++) scanf("%lf", &x[i]);
    // for (int i = 1; i <= 10; i++) scanf("%lf", &f[i]);
    // double avg = 0;
    // for (int i = 6; i <= 10; i++) avg += x[i] - x[i - 5];
    // avg /= 25.0;
    // printf("%f\n", avg);
    // double ans = 0;
    // for (int i = 6; i <= 10; i++) ans += ((x[i] - x[i - 5]) / 5.0 - avg) * ((x[i] - x[i - 5]) / 5.0 - avg);
    // ans /= 4.0; 
    // printf("%f\n", sqrt(ans)); 
    // double avg2 = 0;
    // for (int i = 1; i <= 10; i++) {
    //     avg2 += f[i];
    // }
    // avg2 /= 10;
    // printf("%f\n", avg2);
    // double ans2 = 0;
    // for (int i = 1; i <= 10; i++) {
    //     ans2 += (f[i] - avg2) * (f[i] - avg2);
    // }
    // ans2 /= 9.0;
    // printf("%f\n", sqrt(ans2));
    for (int i = 1; i <= 6; i++) scanf("%lf", &x[i]);
    for (int i = 1; i <= 6; i++) scanf("%lf", &f[i]);
    double ans = 0;
    for (int i = 1; i <= 6; i += 2) ans += (x[i + 1] - x[i]) / (f[i + 1] - f[i]);
    printf("%f", ans / 5.0);
    return 0;
}