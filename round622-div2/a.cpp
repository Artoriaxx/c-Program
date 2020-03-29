#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        if (a > 0) {
            a--;
            ans++;
        }
        if (b > 0) {
            b--;
            ans++;
        }
        if (c > 0) {
            c--;
            ans++;
        }
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c); 
        if (a > 0 && b > 0) {
            a--;
            b--;
            ans++;
        }
        if (a > 0 && c > 0) {
            a--;
            c--;
            ans++;
        }
        if (b > 0 && c > 0) {
            b--;
            c--;
            ans++;
        }
        if (a > 0 && b > 0 && c > 0) {
            ans++;
        }
        printf("%d\n", ans);
    } 
    return 0;
}