/*
1.Floyd倍增，将矩阵乘法改成Floyd：
一个走a步的矩阵和一个走b步的矩阵进行Floyd可以得到一个走a+b步的矩阵
所以可以利用倍增，来求走k条旧路和a条新路所走的权值 
2.初始化注意边界
3.分层图思想：相邻两层加新路的边，这样转移时便可根据到达的层数确定权值 
*/
#include<iostream>
#define inf 0x3f3f3f3f3f3f3f3fLL
#define s 160
using namespace std;
struct matrix{
	long long val[s][s];
	int n;
	
	void init(int m){
		n = m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				val[i][j] = inf;
			}
		}
	}
	
	matrix operator * (const matrix &a) const {
		matrix ans;
		ans.init(n);
		//Floyd 
		for(int k = 1; k <= n; k++){ 
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					ans.val[i][j] = min(ans.val[i][j], val[i][k] + a.val[k][j]);
				}
			}
		}
		
		return ans;
	}
}matrix1;

inline matrix fastpow(matrix a,long long b){
	matrix ans, base = a;
	ans.init(a.n);
	for(int i = 1; i <= ans.n; i++) ans.val[i][i] = 0;//因为乘法定义为Floyd所以i到i的值要赋值为0 
	while (b){                                        //这样才能保证原矩阵和ans矩阵相乘答案不会变 
		if(b & 1){
			ans = ans * base;
		}
		base = base * base;
		b >>= 1;
	}
	return ans;
}

int main(){
	int n, m, a, b;long long k;
	cin>>n>>m>>k>>a>>b;
	matrix1.init(n * b + n);//别忘初始化 
	for(int i = 1; i <= m; i++){
		int x, y, c;
		cin>>x>>y>>c;
		for(int j = 0; j <= b; j++)
			matrix1.val[x + j * n][y + j * n] = c;
	}
	
	for(int i = 1; i <= a; i++){
		int x, y;
		cin>>x>>y;
		for(int j = 0; j < b; j++){
			int c;
			cin>>c;
			matrix1.val[x + j * n][y + n + j * n] = c;
		}
	}
	
	matrix ans1 = fastpow(matrix1, k + b);
	long long ans = inf;
	for(int i = n * b + 1; i <= n * b + n; i++){
		ans = min(ans, ans1.val[1][i]);
	}
	cout<<(ans == inf ? -1 : ans);
	return 0;
}
