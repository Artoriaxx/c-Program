#include<bits/stdc++.h>
using namespace std;
const int maxn = 2050;
inline int getnum(){
	char c; int ans = 0; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1); 
}
int n, m;
int a[maxn][maxn];
int l, r, mid, ans;
int max1, min1;
int vis[maxn][maxn];
inline int check(int x){
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] >= max1 - x && (vis[i - 1][j] == 1 || i == 1)){
				vis[i][j] = 1;
			}
			else break;
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++){
		for (int j = m; j >= 1; j--){
			if (vis[i][j] == 0){
				if (a[i][j] <= min1 + x) continue;
				else flag = false;
			}
			else break;
		}
	}
	return flag;
}
inline int check1(int x){
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] <= min1 + x && (vis[i - 1][j] == 1 || i == 1)){
				vis[i][j] = 1;
			}
			else break;
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++){
		for (int j = m; j >= 1; j--){
			if (vis[i][j] == 0){
				if (a[i][j] >= abs(max1 - x)) continue;
				else flag = false;
			}
			else break;
		}
	}
	return flag;
}
inline int check2(int x){
	memset(vis, 0, sizeof(vis));
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= m; j++){
			if (a[i][j] <= min1 + x && (vis[i + 1][j] == 1 || i == n)){
				vis[i][j] = 1;
			}
			else break;
		}
	}
	bool flag = true;
	for (int i = n; i >= 1; i--){
		for (int j = m; j >= 1; j--){
			if (vis[i][j] == 0){
				if (a[i][j] >= abs(max1 - x)) continue;
				else flag = false;
			}
			else break;
		}
	}
	return flag;
}
inline int check3(int x){
	memset(vis, 0, sizeof(vis));
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= m; j++){
			if (a[i][j] <= abs(max1 - x) && (vis[i + 1][j] == 1 || i == n)){
				vis[i][j] = 1;
			}
			else break;
		}
	}
	bool flag = true;
	for (int i = n; i >= 1; i--){
		for (int j = m; j >= 1; j--){
			if (vis[i][j] == 0){
				if (a[i][j] >= max1 + x) continue;
				else flag = false;
			}
			else break;
		}
	}
	return flag;
}
int tmp;
int main(){
	n = getnum(), m = getnum();
	min1 = 0x7ffffff;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			a[i][j] = getnum();
			r = max(r, a[i][j]);
			max1 = max(max1, a[i][j]);
			min1 = min(min1, a[i][j]);
		}
	}
	tmp = r;
	l = 0;
	ans = 0x7ffffff;
	while (l <= r){
		mid = (l + r) >> 1;
		if (check(mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}
		else {
			l = mid + 1;
		}
	}
	l = 0, r = tmp;
	while (l <= r){
		mid = (l + r) >> 1;
		if (check1(mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}
		else {
			l = mid + 1;
		}
	}
	l = 0, r = tmp;
	while (l <= r){
		mid = (l + r) >> 1;
		if (check2(mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}
		else {
			l = mid + 1;
		}
	}
	l = 0, r = tmp;
	while (l <= r){
		mid = (l + r) >> 1;
		if (check3(mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
