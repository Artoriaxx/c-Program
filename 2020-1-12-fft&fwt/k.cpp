#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
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
        for (int i = 0; i < len; i++) {
            a[i].r /= len;
        }
    }
}

const int N = 4e5 + 50;

int visx[N], visy[N], visxy[N];
cp a[N], b[N];


int main() {
    int t;
    int cse = 0;
    scanf("%d", &t);
    while (t--) {
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int len1 = r + c + 1;
        int len = 1;
        while (len < len1) len <<= 1;
        for (int i = 0; i < len; i++) {
            a[i] = cp(0, 0);
            b[i] = cp(0, 0);
            visx[i] = visy[i] = visxy[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            visx[x] = 1;
            visy[y] = 1;
            visxy[x - y + c - 1] = 1;
        }
        ll numx = 0, numy = 0;
        for (int i = 0; i < r; i++) {
            if (visx[i] == 0) {
                numx++;
                a[i] = cp(1, 0);
            }
        }
        for (int i = 0; i < c; i++) {
            if (visy[i] == 0) {
                numy++;
                b[c - i - 1] = cp(1, 0);
            }
        }
        fft(a, len, 1);
        fft(b, len, 1);
        for (int i = 0; i < len; i++) {
            a[i] = a[i] * b[i];
        }
        fft(a, len, -1);
        ll res = numx * numy;
        for (int i = 0; i < len; i++) {
            res -= (ll)(a[i].r + 0.5) * visxy[i];
        }
        printf("Case %d: %lld\n", ++cse, res);
    }
    return 0;
}