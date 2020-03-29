#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
string s[N];
int son[N * 20][30], id;
ll cnt[N * 20];
void insert(string ss) {
    int p = 0;
    for (int i = 0; i < ss.length(); i++) {
        int c = ss[i] - 'A';
        if (!son[p][c]) son[p][c] = ++id;
        p = son[p][c];
    }
    cnt[p]++;
}
ll sze[N * 20];
int n, k;
ll ans = 0;
void dfs(int x, int dep) {
    sze[x] = cnt[x];
    for (int i = 0; i < 26; i++) {
        if (son[x][i]) {
            dfs(son[x][i], dep + 1);
            sze[x] += sze[son[x][i]];
        }
    }
    while (sze[x] >= k) {
        sze[x] -= k;
        ans += dep;
    }
}
int main() {
    int t;
    scanf("%d", &t);
    int cse = 0;
    while (t--) {
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        memset(sze, 0, sizeof(sze));
        id = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) cin >> s[i];
        ans = 0;
        for (int i = 1; i <= n; i++) {
            insert(s[i]);
        }
        dfs(0, 0);
        
        
        printf("Case #%d: %lld\n", ++cse, ans);
        
    }
    return 0;
}