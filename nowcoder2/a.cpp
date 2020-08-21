#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
const int M = 1e5 + 50;
const int mod = 998244353;
const int base = 233;
char s[N];
vector<long long> h[M];
vector<int> nxt[M];
ll p[N];
int cnt[N];
void getNxt(int id) {
    int m = strlen(s + 1);
    nxt[id].resize(m + 1);
    int j = 0;
    for (int i = 2; i <= m; i++) {
        while (j && s[i] != s[j + 1]) j = nxt[id][j];
        if (s[i] == s[j + 1]) j++;
        nxt[id][i] = j;
    }
}
int main() {
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * base;
    map<ll, int> mp;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        h[i].resize(len + 1);
        h[i][0] = 0;
        for (int j = 1; j <= len; j++) h[i][j] = h[i][j - 1] * base + s[j] - 'a' + 1;
        for (int j = 0; j < len; j++) mp[h[i][len] - h[i][j] * p[len - j]]++;
        getNxt(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < h[i].size(); j++) {
            cnt[j] = mp[h[i][j]];
            cnt[nxt[i][j]] -= cnt[j];
        }
        for (int j = 1; j < h[i].size(); j++) 
            ans = (ans + 1ll * cnt[j] * j % mod * j % mod) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
