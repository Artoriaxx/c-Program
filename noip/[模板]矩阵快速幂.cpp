#include<bits/stdc++.h>
#define maxn 105
#define ll long long
#define p 1000000007
using namespace std;
int n;ll k;
struct matrix{
	ll val[maxn][maxn];
	void build(){
		memset(val, 0, sizeof(val));
		for (int i = 0; i < n; i++){
			val[i][i] = 1;
		}
	}
	matrix operator * (const matrix & a) const {
		matrix ans;
		memset(ans.val, 0, sizeof(ans.val));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					ans.val[i][j] += val[i][k] * a.val[k][j] % p;
				}
				ans.val[i][j] %= p;
			}
		}
		return ans;
	}
};
inline matrix fpow(matrix a, ll b){
	matrix ans, base = a; ans.build();
	while (b){
		if (b & 1){
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d%lld", &n, &k);
	matrix umi;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &umi.val[i][j]);
		}
	}
	matrix saber = fpow(umi, k);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", saber.val[i][j]);
		}
		printf("\n");
	}
	return 0;
}
