#include <bits/stdc++.h>
using namespace std;
const int N = 100;
typedef long long ll;
string s[N];
int t[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }
    string tmp;
    cin >> tmp;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == tmp) {
            pos = i;
            break;
        }
    }
    ll ans = 0;
    for (int i = pos + 1; i <= n; i++) {
        ans += t[i];
    }
    printf("%lld\n", ans);
    return 0;
}