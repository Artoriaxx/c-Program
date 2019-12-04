#include<bits/stdc++.h>
#define re register int
using namespace std;
int n, m;
inline int getnum(){
	int ans = 0; bool flag = false; char c;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1); 
}
int num[15];
int a[15][15];
int c[3];
int check(int x){
	return (x <= 12) && (x % 3 == 0 ? 1 : 0); 
}
int ans;
void dfs(int cnt){
	if (cnt > n){z
		int ans1 = 0;
		for (re i = 1; i <= m; i++){
			c[0] = c[1] = c[2] = 0;
			for (re j = 1; j <= n; j++){
				c[0] += check(a[j][i] + num[j]);
				c[1] += check(a[j][i] + num[j] + 1);
				c[2] += check(a[j][i] + num[j] + 2);
			}
			ans1 += max(c[0], max(c[1], c[2]));
		}
		ans = max(ans, ans1);
		return;
	}
	for (re i = 0; i <= 2; i++){
		num[cnt] = i;
		dfs(cnt + 1);
	}
}
int main(){
	n = getnum(), m = getnum();
	for (re i = 1; i <= n; i++){
		for (re j = 1; j <= m; j++){
			a[i][j] = getnum();
		}
	}
	ans = 0;
	dfs(1);
	cout<<ans;
	return 0;
}
