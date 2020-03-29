#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
char a[N];
int pre1[N], pre2[N];
int vis[N];
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", a + 1);
        for (int i = 1; i <= n; i++) {
            pre1[i] = pre2[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == '<') {
                pre1[i]++;
            }
            else if (a[i] == '>') {
                pre2[i]++;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (pre1[i] == 1) pre1[i] += pre1[i + 1];
            if (pre2[i] == 1) pre2[i] += pre2[i + 1];
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        int now = n;
        if (a[1] == '<') {
            now -= pre1[1];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == '>')  {
                if (pre2[i] > 1) {
                    printf("%d ", now);
                    vis[now] = 1;
                    while (vis[now]) {
                        now--;
                    }
                }
                else if (pre2[i] == 1) {
                    printf("%d ", now);
                    vis[now] = 1;
                    int tmp = pre1[i + 1];
                    while (tmp) {
                        if (!vis[now]) tmp--;
                        now--;
                    }
                }
            }
            else {
                
                printf("%d ", now);
                vis[now] = 1;
                while (vis[now]) {
                    now++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                printf("%d\n", i);
            }
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        now = 1;
        if (a[1] == '>') {
            now += pre2[1];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == '<')  {
                if (pre1[i] > 1) {
                    printf("%d ", now);
                    vis[now] = 1;
                    while (vis[now]) {
                        now++;
                    }
                }
                else if (pre1[i] == 1) {
                    printf("%d ", now);
                    vis[now] = 1;
                    int tmp = pre2[i + 1];
                    while (tmp) {
                        if (!vis[now]) tmp--;
                        now++;
                    }
                }
            }
            else {
                
                printf("%d ", now);
                vis[now] = 1;
                while (vis[now]) {
                    now--;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}