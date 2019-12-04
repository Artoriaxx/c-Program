#include<bits/stdc++.h>
#define ll long long
#define maxn 100050
using namespace std;
int n, m, p;
int a[maxn];
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
struct segment_tree{
#define lson (o << 1)
#define rson (o << 1 | 1)
	ll addv[maxn << 2], sumv[maxn << 2], addu[maxn << 2];
	inline void pushup(int o){sumv[o] = (sumv[lson] + sumv[rson]) % p;}
	inline void pushdown(int o, int l, int r){
		//pushdown里一定先乘后加 
		//pushdown里一定先乘后加 
		//pushdown里一定先乘后加 
		//重要的事说三遍！！！！ 
		if (addu[o] != 1){//这个地方判断的时候是！=1 
			addu[lson] = addu[lson] * addu[o] % p; addu[rson] = addu[rson] * addu[o] % p;
			sumv[lson] = sumv[lson] * addu[o] % p; sumv[rson] = sumv[rson] * addu[o] % p;
			addv[lson] = addv[lson] * addu[o] % p; addv[rson] = addv[rson] * addu[o] % p;//addv的标记也要变 
			addu[o] = 1;//这地方重置为1 
		}
		if (addv[o]){
			addv[lson] = (addv[lson] + addv[o]) % p; addv[rson] = (addv[rson] + addv[o]) % p;
			ll mid = (l + r) >> 1;
			sumv[lson] = (sumv[lson] + addv[o] * (mid - l + 1)) % p; sumv[rson] = (sumv[rson] + addv[o] * (r  - mid)) % p;
			addv[o] = 0;
		}
		return;
	}
	inline void build(int o, int l, int r){
		addv[o] = 0;
		addu[o] = 1;
		ll mid = (l + r) >> 1;
		if (l == r){sumv[o] = a[l] % p; return;}
		build(lson, l, mid), build(rson, mid + 1, r);
		pushup(o);
	}
	inline void updateplus(int o, int l, int r, int ql, int qr, int v){
		if (ql <= l && r <= qr){
			sumv[o] = (sumv[o] + v * (r - l + 1) % p) % p; addv[o] = (addv[o] + v % p) % p; return;
		}
		ll mid = (l + r) >> 1;
		pushdown(o, l, r);
		if (ql <= mid) updateplus(lson, l, mid, ql, qr, v);
		if (qr > mid) updateplus(rson, mid + 1, r, ql, qr, v);
		pushup(o);
	}
	inline void updatemul(int o, int l, int r, int ql, int qr, int v){
		if (ql <= l && r <= qr){
			sumv[o] = (sumv[o] * v) % p; addu[o] = (addu[o] * v) % p; addv[o] = (addv[o] * v % p) % p; return;
		}
		ll mid = (l + r) >> 1;
		pushdown(o, l, r);
		if (ql <= mid) updatemul(lson, l, mid, ql, qr, v);
		if (qr > mid) updatemul(rson, mid + 1, r, ql, qr, v);
		pushup(o);
	}
	inline ll querysum(int o, int l, int r, int ql, int qr){
		if (ql <= l && r <= qr){
			return sumv[o] % p;
		}
		ll mid = (l + r) >> 1, ans = 0;
		pushdown(o, l, r);
		if (ql <= mid) ans = (ans + querysum(lson, l, mid, ql, qr)) % p;
		if (qr > mid) ans = (ans + querysum(rson, mid + 1, r, ql, qr)) % p;
		return ans;
	}
} t;
int main(){
	n = getnum(), m = getnum(), p = getnum();
	for (int i = 1; i <= n; i++){
		a[i] = getnum();
	}
	t.build(1, 1, n);
	for (int i = 1; i <= m; i++){
		int ti = getnum();
		int ql, qr, v;
		if (ti == 2){
			ql = getnum(), qr = getnum(), v = getnum();
			t.updateplus(1, 1, n, ql, qr, v);
		}
		if (ti == 1){
			ql = getnum(), qr = getnum(), v = getnum();
			t.updatemul(1, 1, n, ql, qr, v);
		}
		if (ti == 3){
			ql = getnum(), qr = getnum();
			ll ans = t.querysum(1, 1, n, ql, qr) % p;
			printf("%lld\n", ans);
		}
	}
	return 0;
}