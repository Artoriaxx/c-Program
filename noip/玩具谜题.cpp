#include<cstdio>
#include<iostream>
#define maxn 100050
using namespace std;
int a[maxn];char b[maxn][15];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%s", &a[i], b[i]);
	}
	int p, q;
	int vis = 1;
	a[0] = a[n];
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &p, &q);
		if(p == 0){
			int cnt = vis;
			if(a[cnt] == 0)
			vis = (vis + n - q) % n;
			if(a[cnt] == 1)
			vis = (vis + n + q) % n;
		}
		if(p == 1){
			int cnt = vis;
			if(a[cnt] == 0)
			vis = (vis + n + q) % n;
			if(a[cnt] == 1)
			vis = (vis + n - q) % n;
		}
	}
	if(vis == 0) vis = n;
	printf("%s", b[vis]);
	return 0;
}
