#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 10010
#define maxm 1010
#define inf 0x3f3f3f3f
using namespace std;
int r[maxn],l[maxn],f[maxn][maxm],up[maxn],down[maxn];
int main(){
	int n, m, k;
	cin>>n>>m>>k;
	r[n] = m + 1;
	l[n] = 0;
	for(int i = 0;i < n;i++){
		cin>>up[i]>>down[i];
		r[i] = m + 1;
		l[i] = 0;
	}
	int x;
	for(int i = 1;i <= k;i++){
		cin>>x;
		cin>>l[x]>>r[x];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			f[i][j] = inf;
		}
	}
	f[0][0] = inf;
	for(int i = 1;i <= n;i++){
		for(int j = up[i - 1];j <= m;j++){
			f[i][j] = min(f[i][j],f[i - 1][j - up[i - 1]] + 1);
			f[i][j] = min(f[i][j],f[i][j - up[i - 1]] + 1);
		}
		for(int j = m - up[i - 1];j <= m;j++){
			f[i][m] = min(f[i][m],f[i - 1][j] + 1);
			f[i][m] = min(f[i][m],f[i][j] + 1);
		}
		for(int j = l[i] + 1;j <= r[i] - 1;j++){
			if(j + down[i - 1] <= m){
				f[i][j] = min(f[i][j], f[i - 1][j + down[i - 1]]);
			}
		}
		for(int j = 1; j <= l[i]; j++)
			f[i][j] = inf;
		for(int j = r[i]; j <= m; j++)
			f[i][j] = inf;
	}
	int ans = inf;
	int cnt = k;
	for(int i = n; i >= 1; i--){
		for(int j = l[i] + 1; j <= r[i] - 1; j++)
			ans = min(ans, f[i][j]);
		if(ans != inf) break;
		if(r[i] != m + 1) cnt--;
		
	}
	if(cnt == k) cout<<"1"<<endl<<ans;
	else cout<<"0"<<endl<<cnt;
	return 0;
}
