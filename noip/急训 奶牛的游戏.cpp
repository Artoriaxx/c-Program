#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, t;
char s[50][50];
int vis[50][50];
int ans = 0;
int cond[50];
int vis1[50];
inline int check(){
	for (int i = 1; i <= t; i++){
		int flag = 1;
		memset(vis1, 0, sizeof(vis1));
		for (int j = 1; j <= n; j++){
			vis1[cond[j]]++;
		}
		for (int j = 1; j <= m; j++){
			if (vis[i][j] != 0){
				if (vis1[j] >= vis[i][j]) continue;
				else{
					flag = 0;
					break;	
				}
			} 
		}
		if (flag == 1) return 1;
	}
	return 0;
}
void dfs(int step){
	if (step == n){
		if(check()){
			ans++;
		}
		return;
	}
	for (int i = 1; i <= m; i++){
		cond[step + 1] = i;
		dfs(step + 1);
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &t);
	int u;
	for (int i = 1; i <= t; i++){
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= strlen(s[i] + 1); j++){
			if (j % 4 == 1){
				u = s[i][j] - '0';
			}
			if (j % 4 == 2 || j % 4 == 0){
				continue;
			}
			if (j % 4 == 3){
				vis[i][s[i][j] - '0'] += u;
			}
		}
	}
	dfs(0);
	printf("%d", ans);
}
