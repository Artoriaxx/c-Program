#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r++;
    }
    printf("%d", r + l + 1);
    return 0;
}