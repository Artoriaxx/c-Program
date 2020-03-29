#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 50;
int a[N], b[N];
struct node {
    int x, y;
};
int len[N];
int len1[N];
typedef long long ll;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    vector<node> dec;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            dec.push_back(node{i, k / i});
            if (k / i != i) dec.push_back(node{k / i, i});
        }
    }
    vector<node> mat;
    vector<int> l;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (b[i] == 1) cnt++;
        else {
            if (len[cnt] == 0) l.push_back(cnt);
            len[cnt]++;
            cnt = 0;
        }
    }
    if (cnt != 0) {
        if (len[cnt] == 0) l.push_back(cnt);
        len[cnt]++;
        cnt = 0;
    }
    vector<int> l1;
    
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) cnt++;
        else {
            if (len1[cnt] == 0) l1.push_back(cnt);
            len1[cnt]++;
            cnt = 0;
        }
    }
    if (cnt != 0) {
        if (len1[cnt] == 0) l1.push_back(cnt);
        len1[cnt]++;
        cnt = 0;
    }
    ll ans = 0;
    for (int i = 0; i < l1.size(); i++) {
        for (int j = 0; j < l.size(); j++) {
            int r = l1[i], c = l[j];
            for (int k = 0; k < dec.size(); k++) {
                if (r - dec[k].x + 1 > 0 && c - dec[k].y + 1 > 0) {
                    ans += (ll)(r - dec[k].x + 1) * (ll)(c - dec[k].y + 1) * (ll)len[c] * (ll)len1[r];
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}