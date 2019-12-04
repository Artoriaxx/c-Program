#include<bits/stdc++.h>
using namespace std;
const int maxn = 50050;
inline int getnum(){
	char c; int ans = 0; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int n, m, t, x, y, ans;
int fa[maxn * 3];
int find(int x){
	return fa[x] == x ? x : find(fa[x]);
}
inline int sample(int x, int y){
	if (find(x) == find(y)) return 1;
	else return 0;
}
inline int merge(int x, int y){
	int xi = find(x), yi = find(y);
	if (xi != yi) fa[xi] = yi;
}
int main(){
	n = getnum(), m = getnum();
	for (int i = 1; i <= n * 3; i++){
		fa[i] = i; 
	}
	for (register int i = 1; i <= m; i++){
		t = getnum(), x = getnum(), y = getnum();
		if (x <= 0 || x > n || y <= 0 || y > n){
			ans++; continue;
		}
		else {
			if (t == 2){
				if (sample(x, y) || sample(x, y + 2 * n)){
					ans++;
				}
				else {
					merge(x, y + n);
					merge(x + n, y + 2 * n);
					merge(x + 2 * n, y);
				}
			}
			if (t == 1){
				if (sample(x, y + n) || sample(x, y + 2 * n)){
					ans++;
				}
				else {
					merge(x, y);
					merge(x + n, y + n);
					merge(x + 2 * n, y + 2 * n);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
