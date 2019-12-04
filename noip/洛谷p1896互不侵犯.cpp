#include<bits/stdc++.h>
#define ll long long
#define re register int
using namespace std;
int n, k, cnt = 0;
int pos[1 << 10];
int num[1 << 10];
void dfs(int tmp, int step, int sum){
	if (step > n){
		pos[++cnt] = tmp;
		num[cnt] = sum;
		return;
	}
	dfs(tmp + (1 << step - 1), step + 2, sum + 1);
	dfs(tmp, step + 1, sum);
}
inline int check(int x, int y){
	return (((x & y) || ((x >> 1) & y) || ((x << 1) & y)) ? 0 : 1);
}
ll f[11][40][1 << 10];
int main(){
	scanf("%d%d", &n, &k);
	dfs(0, 1, 0);
	for (re i = 1; i <= cnt; i++) f[1][num[i]][pos[i]] = 1;
	for (re i = 2; i <= n; i++){
		for (re j = 1; j <= cnt; j++){
			for (re ki = 1; ki <= cnt; ki++){
				if (check(pos[j], pos[ki])){
					for (re s = k; s >= num[j]; s--){
						f[i][s][pos[j]] += f[i - 1][s - num[j]][pos[ki]];
					}
				}
			}
		}
	}
	ll ans = 0;
	for (re i = 1; i <= cnt; i++) ans += f[n][k][pos[i]];
	printf("%lld", ans);
	return 0;
}
