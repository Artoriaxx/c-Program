/*
Cij=∑Aik+Bkj (1<=k<=n,n是矩阵大小)  注意i表示列，j表示行

*/
#include<iostream>
#include<cstring>
#define p 998224353
#define s 21
using namespace std;
struct matrix{
	long long val[s][s]; 
	//构造一个单位矩阵，乘以其他矩阵其他矩阵值不变 
	void build(){ 
		memset(val, 0, sizeof(val));
		for(int i = 0; i < s; i++)
			val[i][i] = 1;
	}
	
	void init(){
		memset(val, 0, sizeof(val));
	}
	//重新定义矩阵乘法 
	matrix operator * (const matrix & a) const {
		matrix ans;
		ans.init();
		for(int i = 0; i < s; i++){
			for(int j = 0; j < s; j++){
				for(int k = 0; k < s; k++){
					ans.val[i][j] += val[i][k] * a.val[k][j] % p;
				}
				ans.val[i][j] %= p;
			}
		}
		return ans;
	}
};
//矩阵快速幂 
matrix fastpow(matrix a,long long b){
	matrix ans,base = a;
	ans.build();
	while (b){
		if (b & 1){
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
	return ans;
}

long long ans[s],now[s];

int main(){
	int n,c;long long k;
	cin>>n>>k>>c;
	ans[0] = 1;
	for(int i = 1; i <= n; i++){
		long long a,b;int y;
		cin>>a>>b>>y;
		matrix x;
		x.init();
		for(int j = 0; j <= y; j++){
			x.val[j][j] = 1;
			if(j > 0) x.val[j][j - 1] = 1;//构建本题矩阵，注意边界 
			if(j < y) x.val[j][j + 1] = 1;//矩阵动态规划 
		}
		if(b > k) b = k;//超出目的地边界就按目的地来算 
		matrix c = fastpow(x, b - a);//快速幂算走b - a步转移 
		memset(now, 0, sizeof(now));
		for(int i = 0; i < s; i++){
			for(int j = 0; j < s; j++){
				(now[i] += ans[j] * c.val[i][j] % p) %= p;//用now数组记录转移 
			}
		}
		for(int i = 0; i < s; i++){
			ans[i] = now[i] % p;//将now数组 % p赋给ans，转移下一次 
		}
	}
	cout<<ans[0];//ans[0]即为答案 
	return 0;
}
