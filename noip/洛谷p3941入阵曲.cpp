#include<bits/stdc++.h>
#define re register int
#define ll long long
using namespace std;
int a[450][450];
ll sum[450][450];
ll f[450];
ll tmp[1000050];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (re i = 1; i <= n; i++){
		for (re j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			sum[i][j] = (sum[i][j - 1] + a[i][j]) % k;
		}
	}
	ll ans = 0;
	for (int l = 1; l <= m; l++){
		for (int r = l; r <= m; r++){
			for (re i = 1; i <= n; i++){
				f[i] = (f[i - 1] + sum[i][r] - sum[i][l - 1] + k) % k;
				tmp[f[i]] = 0;
			}
			for (re i = 1; i <= n; i++){
				if (!f[i]){
					ans++;
				}
				ans += tmp[f[i]]; tmp[f[i]]++;//观察到%k意义下相等的数相减必定是k的倍数，所以只需记录之前%k = f[i]的个数 
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
