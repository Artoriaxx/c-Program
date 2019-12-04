#include<iostream>
#include<cstring>
#include<cmath>
#define maxn 10005
using namespace std;
int a[maxn],f[maxn][150];
int main(){
	int t;
	cin>>t;
	int n, k;
	while(t--){
		cin>>n>>k;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			a[i] = abs(a[i]) % k;
		}
		memset(f, 0, sizeof(f));
		f[1][a[1]] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < k; j++){
				if(f[i - 1][j]){
					f[i][(j + a[i]) % k] = 1;
					f[i][(j - a[i] + k) % k] = 1;
				}
			}
		}
		if(f[n][0]) cout<<"Divisible\n";
		else cout<<"Not divisible\n";
	}
	return 0;
}
