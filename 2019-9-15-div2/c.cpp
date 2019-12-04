#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
char s1[N], s2[N];
int pos1[N], pos2[N];
struct node {
    int l, r;
} ans[N];
int main() {
    int n; scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= n; i++) {
        if (s1[i] == 'a' && s2[i] == 'b') {
            pos1[++tot1] = i;
        }
        else if (s1[i] == 'b' && s2[i] == 'a') {
            pos2[++tot2] = i;
        }
    }
    if ((tot1 + tot2) % 2 == 1) {
        puts("-1");
    }
    else {
        int cnt = 0;
        int now = 0;
        int tmp1 = tot1, tmp2 = tot2;
        while (tot1 > 1) {
            ans[++cnt].l = pos1[++now];
            ans[cnt].r = pos1[++now];
            tot1 -= 2;
        }
        now = 0;
        while (tot2 > 1) {
            ans[++cnt].l = pos2[++now];
            ans[cnt].r = pos2[++now];
            tot2 -= 2;
        }
        if (tot1 != 0) {
            ans[++cnt].l = pos1[tmp1];
            ans[cnt].r = pos1[tmp1];
            ans[++cnt].l = pos1[tmp1];
            ans[cnt].r = pos2[tmp2];
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++) {
            printf("%d %d\n", ans[i].l, ans[i].r);
        }
    }
    return 0;
}