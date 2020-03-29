#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        string a, b;
        a.clear();
        b.clear();
        cin >> a >> b;
        string c = a;
        if (a < b) {
            cout << a << "\n";
            continue;
        }
        sort(c.begin(), c.end());
        int pos = -1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != c[i]) {
                pos = i;
                break;
            }
        }
        char d = a[pos];
        int t = pos;
        for (int i = pos + 1; i < a.length(); i++) {
            if (a[i] <= d) {
                t = i;
                d = a[i];
            }
        }
        swap(a[pos], a[t]);
        if (a < b) cout << a << "\n";
        else printf("---\n");
    }
    return 0;
}