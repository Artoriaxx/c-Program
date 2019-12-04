#include<bits/stdc++.h>
#define maxn 100050
#define ll long long
using namespace std;
int a[maxn];
struct segment_tree{
#define lson (o << 1)
#define rson (o << 1 | 1)
	ll sumv[maxn << 2], addv[maxn << 2];
	inline void pushup(int o){sumv[o] = sumv[lson] + sumv[rson];}//这里是=而不是+= 
	inline void pushdown(int o, int l, int r){
		if (!addv[o]) return;
		addv[lson] += addv[o], addv[rson] += addv[o];
		ll ri = (l + r) >> 1, li = ri + 1;
		sumv[lson] += addv[o] * (ri - l + 1);
		sumv[rson] += addv[o] * (r - li + 1);
		addv[o] = 0;
	}
	inline void build(int o, int l, int r){
		addv[o] = 0;
		if (l == r){
			sumv[o] = a[l]; return;
		}
		ll mid = (l + r) >> 1;
		build(lson, l, mid); build(rson, mid + 1, r);
		pushup(o);
	}
	inline void updata(int o, int l, int r, int ql, int qr, ll v){
		if (ql <= l && r <= qr){
			sumv[o] += v * (r - l + 1);
			addv[o] += v;
			return;
		}
		ll mid = (l + r) >> 1;
		pushdown(o, l, r);
		if (ql <= mid) updata(lson, l, mid, ql, qr, v);
		if (qr > mid) updata(rson, mid + 1, r, ql, qr, v);
		pushup(o);
	}
	inline ll query(int o, int l, int r, int ql, int qr){
		if (ql <= l && r <= qr) return sumv[o];
		ll mid = (l + r) >> 1, ans = 0;
		pushdown(o, l, r);
		if (ql <= mid) ans += query(lson, l, mid, ql, qr);
		if (qr > mid) ans += query(rson, mid + 1, r, ql, qr);
		return ans;
	}
} tree;
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	tree.build(1, 1, n);
	for (int i = 1; i <= m; i++){
		int t, l, r, v;
		scanf("%d", &t);
		if (t == 2){
			scanf("%d%d", &l, &r);
			ll ans = tree.query(1, 1, n, l, r);
			printf("%lld\n", ans);
		}
		else if (t == 1){
			scanf("%d%d%d", &l, &r, &v);
			tree.updata(1, 1, n, l, r, v);
		}
	}
	return 0;
	
}
