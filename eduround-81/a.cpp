#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            for (int i = 1; i <= x / 2; i++) {
                printf("1");
            }
            puts("");
        }
        else {
            putchar('7');
            x -= 3;
            for (int i = 1; i <= x / 2; i++) {
                printf("1");
            }
            puts("");
        }
    }
    return 0;
}