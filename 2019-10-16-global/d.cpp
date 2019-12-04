#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int a[N];
int f[N];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int nowm = 0;
    int cnt = 0;
    nowm = a[1];
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        cnt++;
        int v = nowm / 2;
        if (nowm % 2 != 0) v++;
        if (a[i] < v) {
            flag = true;
            break;
        }
        if (a[i] > nowm) nowm = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt++;
        int v = nowm / 2;
        if (nowm % 2 != 0) v++;
        if (a[i] < v) {
            flag = true;
            break;
        }
        if (a[i] > nowm) nowm = a[i];
    }
    f[1] = cnt;
    if (!flag) f[1] = -1;
    for (int i = n; i >= 2; i--) {
        int j = i + 1; if (j > n) j -= n;
        int v = a[i] / 2;
        if (a[i] % 2 != 0) v++;
        if (v > a[j]) {
            f[i] = 1;
        }
        else {
            f[i] = f[j] + 1;
            if (f[j] == -1) f[i] = -1;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", f[i]);
    return 0;
}