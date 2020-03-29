#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int a[N], cor[N];
int vis[N];
int n;
int now = 0;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            puts("1");
            for (int i = 1; i <= n; i++) {
                printf("1 ");
            }
            puts("");
            continue;
        }
        int l = 0;
        for (int i = 0; i < n; i++) {
            int nxt = (i + 1) % n;
            if (a[nxt] == a[i]) {
                l = nxt;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cor[(l+i)%n] = i % 2;
        }
        if (cor[(l-1+n)%n] != cor[l] || a[(l-1+n)%n] == a[l]) {
            puts("2");
            for (int i = 0; i < n; i++) {
                printf("%d ", cor[i] + 1);
            }
        }
        else {
            cor[(l-1+n)%n] = 2;
            puts("3");
            for (int i = 0; i < n; i++) printf("%d ", cor[i] + 1);
        }
        puts("");
    }
    return 0;
}