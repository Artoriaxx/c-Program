#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
int a[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        bool sta = true;
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] < i - 1) {
                pos1 = i - 1;
                break;
            }
        }
        int j = 0;
        for (int i = n; i >= 1; i--, j++) {
            if (a[i] < j) { 
                pos2 = i + 1;
                break;
            }
        }
        if (pos1 >= pos2) {
            puts("YES");
        }
        else if (pos1 == -1) {
            puts("YES");
        }
        else if (pos2 == -1) {
            puts("YES");
        }
        else {
            puts("NO");
        }
        
    }
    return 0;
}