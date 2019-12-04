#include<iostream>
#include<cstdio>
using namespace std;
const int p = 1e9 + 7;
long long f[2][5005],sum[2][5005];
int main(){
	int n, a, b, k;
	cin>>n>>a>>b>>k;
	if(a < b){
		int q;
		if(2 * a - b <= 0) q = 1;
		else q = 2 * a - b + 1;
		for(int i = 1; i <= n; i++){
			f[1][i] = 1;
			if(i == a || i == b || i < q) f[1][i] = 0;
			sum[1][i] = sum[1][i - 1] + f[1][i];
		}
		for(int i = 2; i <= k; i++){
			for(int j = 1; j < b; j++){
				int t = (j + b) / 2;
				if((j + b) % 2 == 0) t--;
				f[i & 1][j] = (sum[(i + 1) & 1][j - 1] + sum[(i + 1) & 1][t] - sum[(i + 1) & 1][j] + p) % p;
				sum[i & 1][j] = (sum[i & 1][j - 1] + f[i & 1][j] + p) % p;
			}
		}
	}
	else{	
		int q;
		if(2 * a - b > n) q = n;
		else q = 2 * a - b - 1;
		for(int i = b + 1; i <= n; i++){
			f[1][i] = 1;
			if(i == a || i == b || i > q) f[1][i] = 0;
			sum[1][i] = sum[1][i - 1] + f[1][i];
		}
		for(int i = 2; i <= k; i++){
			for(int j = b + 1; j <= n; j++){
				int t = (j + b) / 2;
				f[i & 1][j] = (sum[(i + 1) & 1][n] - sum[(i + 1) & 1][j] + sum[(i + 1) & 1][j - 1] - sum[(i + 1) & 1][t] + p) % p;
				sum[i & 1][j] = (sum[i & 1][j - 1] + f[i & 1][j] + p) % p;
			}
		}
	}
	if(a < b) cout<<(sum[k & 1][b - 1] + p) % p;
	if(a > b) cout<<(sum[k & 1][n] + p) % p; 
	return 0;
}
