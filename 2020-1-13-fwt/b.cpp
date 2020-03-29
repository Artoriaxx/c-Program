#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fwt(ll a[], int len, int op) {
    for (int h = 2; h <= len; h <<= 1) {
        for (int j = 0; j < len; j += h) {
            for (int k = j; k < j + h / 2; k++) {
                ll u = a[k], t = a[k + h / 2];
                a[k] = u + t;
                a[k + h / 2] = u - t;
                if (op == -1) {
                    a[k] /= 2; a[k + h / 2] /= 2;
                }
            }
        }
    }
}
const int N = 2e6;
char ch[20][100050];
ll a[N], b[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", ch[i]);
    }
    int len = 1 << n;
    for (int i = 0; i < m; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            x += (ch[j][i] - '0') << j;
        }
        a[x]++;
    }
    for (int i = 1; i < len; i++) {
        b[i] = b[i >> 1] + (i & 1);
    }
    for (int i = 0; i < len; i++) {
        b[i] = min(b[i], n - b[i]);
    }
    fwt(a, len, 1);
    fwt(b, len, 1);
    for (int i = 0; i < len; i++) {
        a[i] = a[i] * b[i];
    }
    fwt(a, len, -1);
    ll ans = 1e18;
    for (int i = 0; i < len; i++) {
        ans = min(ans, a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}