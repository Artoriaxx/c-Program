#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100050;
inline int getnum(){
	int ans = 0; char c; bool flag = false;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = true; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * (flag ? -1 : 1);
}
int a[maxn][4];
int f[maxn][5];
int main(){
	int n;
	n = getnum();
	for (int i = 1; i <= n; i++){
		a[i][1] = getnum();
	}
	for (int i = 1; i <= n; i++){
		a[i][2] = getnum();
	}
	for (int i = 1; i <= n; i++){
		a[i][3] = getnum();
	}
	for (int i = 1; i <= 4; i++){
		f[1][i] = 1;
	}
	for (int i = 2; i<= n; i++){
		for (int j = 1; j < i; j++){
			for (int k = 1; k <= 3; k++){
				if (a[i][1] >= a[j][k]){
					f[i][1] = max(f[i][1], f[j][k] + 1);
					if (k == 3)
					f[i][1] = max(f[i][1], f[j][4] + 1);
				}
				if (a[i][2] <= a[j][k]){
					f[i][2] = max(f[i][2], f[j][k] + 1);
					if (k == 3)
					f[i][2] = max(f[i][2], f[j][4] + 1);
				}
				if (a[i][3] <= a[j][k]){
					if (k != 3){
						f[i][4] = max(f[i][4], f[j][k] + 1);
					}
					else {
						f[i][4] = max(f[i][4], f[j][4] + 1);
					}
				}
				if (a[i][3] >= a[j][k]){
						f[i][3] = max(f[i][3], f[j][k] + 1);
				}
			}
		} 
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++){
		ans = max(ans, f[n][i]);
	}
	printf("%d", ans);
	return 0;
}
