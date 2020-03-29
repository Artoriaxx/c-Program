#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
typedef long long ll;
ll vis[N];
int b[N];
int n;
ll ans = 0;
int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        b[i] -= i;
        vis[b[i] + (int)2e5 + 50] += b[i] + i;
        ans = max(vis[b[i] + (int)2e5 + 50], ans);
    }
    printf("%lld\n", ans);
    return 0;
}