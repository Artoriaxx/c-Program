#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int N = 2e6 + 50;
typedef long long ll;
struct cp {
    double r, i;
    cp(double r = 0, double i = 0): r(r), i(i) {}
    cp operator + (const cp &b) {
        return cp(r + b.r, i + b.i);
    }
    cp operator - (const cp &b) {
        return cp(r - b.r, i - b.i);
    }
    cp operator * (const cp &b) {
        return cp(r * b.r - i * b.i, r * b.i + i * b.r);
    }
};
void change(cp a[], int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if (j < k) j += k; 
    }
}
void fft(cp a[], int len, int op) {
    change(a, len);
    for (int h = 2; h <= len; h <<= 1) {
        cp wn(cos(-op * 2 * pi / h), sin(-op * 2 * pi / h));
        for (int j = 0; j < len; j += h) {
            cp w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                cp u = a[k];
                cp t = w * a[k + h / 2];
                a[k] = u + t;
                a[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (op == -1) {
        for (int i = 0; i < len; i++) a[i].r /= len;
    }
}
cp a[N], b[N];
double p[550][550];
int main() {
    int n, m;
    double r;
    while (~scanf("%d%d%lf", &n, &m, &r)) {
        int R = ceil(r);
        
        int M = max(n, m) + 2 * R;
        int len = 1;
        while (len <= M * M) len <<= 1;
        for (int i = 0; i < len; i++) {
            a[i] = cp(0, 0);
            b[i] = cp(0, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lf", &p[i][j]);
                a[i * M + j] = cp(p[i][j], 0);
            }
        }
        for (int i = -R; i <= R; i++) {
            for (int j = -R; j <= R; j++) {
                if (sqrt(i * i + j * j) < r) {
                    b[(i + R) * M + j + R] = cp(1.0 / (sqrt(i * i + j * j) + 1.0), 0);
                }
            }
        }
        fft(a, len, 1);
        fft(b, len, 1);
        for (int i = 0; i < len; i++) {
            a[i] = a[i] * b[i];
        }
        fft(a, len, -1);
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, a[(i + R) * M + j + R].r);
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}