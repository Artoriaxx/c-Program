#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
long long f[105][105][450];
int w[105],c[150];
int main(){
	int n, w1;
	cin>>n>>w1;
	for(int i = 1; i <= n; i++){
		cin>>w[i]>>c[i];
	}
	int minus = c[1];
	for(int i = 1; i <= n; i++){
		c[i] -= minus;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			for(int k = n * 3; k >= 0; k--){
				if(k >= c[i] && j * minus + k <= w1)
				f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - 1][k - c[i]] + w[i]);
				if(k < c[i] && j * minus + k <= w1)
				f[i][j][k] = f[i - 1][j][k];
				ans = max(ans, f[i][j][k]);
			}
		}
	}
//	for(int k = 0; k <= n; k++) cout<<f[4][4][k]<<" ";
	cout<<ans;
	return 0;
}
