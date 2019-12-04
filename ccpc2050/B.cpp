#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int yy, mm, dd;
        scanf("%d-%d-%d", &yy, &mm, &dd);
        int h, min, s;
        scanf("%d:%d:%d", &h, &min, &s);
        int x = (60 - min - 1) * 60 + (60 - s);
        cout << x % 100 << endl;
    }
    return 0;
}