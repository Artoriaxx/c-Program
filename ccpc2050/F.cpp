#include<bits/stdc++.h>
#define N 1005
using namespace std;
struct node {
    int a, b, c;
} ch[N];
bool cmp(node x, node y) {
    return x.a == y.a ? x.b - x.a + x.c > y.b - y.a + y.c : x.a > y.a;
}
int f[10005];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d%d", &n, &c);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (x <= y) {
                ch[++cnt].a = x;
                ch[cnt].b = y;
                ch[cnt].c = z;
            }
        }
        sort (ch + 1, ch + cnt + 1, cmp);
        f[0] = c;
        for (int i = 2; i <= cnt; i++) {
            for (int j = 1; j <= i; j++) {

            }
        }
        for 
    }
}