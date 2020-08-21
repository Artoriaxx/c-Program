#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll tot[12];
	node() {
		for (int i = 0; i <= 11; i++) tot[i] = 0;
	}
    bool operator == (const node &b) const {
        for (int i = 0; i <= 9; i++) if (tot[i] != b.tot[i]) return 0;
        return 1;
    }
    bool operator < (const node &b) const {
        for (int i = 0; i <= 9; i++) if (tot[i] < b.tot[i]) return 1;
        return 0;
    }
} f[20][20];
map<node, node> mp;
int digit[15];
node sum;
ll a, b; int d;
node dfs(int pos, int lead, bool flag) {
	if (pos <= 0) {
		node now;
		if (lead == 10) {
			now.tot[10] = 0;
            return now;
		}
        else {
			now.tot[10] = 1;
			now.tot[lead] = 1;
		}
        int mx = 0, num;
        for (int i = 0; i <= 9; i++) {
            if (sum.tot[i] > mx) {
                num = i;
                mx = sum.tot[i];
            }
        }
        int cnt = 0;
        for (int i = 0; i <= 9; i++) {
            if (sum.tot[i] == mx) cnt++;
        }
        if (cnt == 1 && num == d) now.tot[11]++;
		return now;
	}
    
	if (!flag && mp.count(sum)) {
		return mp[sum];
	}
    int mx = 0;
    for (int i = 0; i <= 9; i++) {
        if (sum.tot[i] > mx) mx = sum.tot[i];
    }
    if (pos < mx - sum.tot[d]) {
        
        node tmp;
        tmp.tot[11] = 0;
        mp[sum] = tmp;
        return tmp;
    }
	node now;
	int sze = flag ? digit[pos] : 9;
	for (int i = 0; i <= sze; i++) {
		node ans;
        if (i == 0 && lead == 10);
        else sum.tot[i]++;
		if (lead == 10 && i == 0) ans = dfs(pos - 1, 10, flag && (i == sze)); 
        else ans = dfs(pos - 1, i, flag && (i == sze));
        if (i == 0 && lead == 10);
        else sum.tot[i]--;
		for (int j = 10; j <= 11; j++) {
			now.tot[j] += ans.tot[j];
		}
	}
	if (!flag) mp[sum] = now;
	return now;
}
node solve (ll x) {
	int len = 0;
	while (x) {
		digit[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 10, 1);
}
int main () {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%d", &a, &b, &d);
        memset(f, -1, sizeof(f));
        node l = solve(a - 1);
        sum = node();
        node r = solve(b);
        printf("%lld\n", r.tot[11] - l.tot[11]);
    }
	
	return 0;
}
//1000000000000000