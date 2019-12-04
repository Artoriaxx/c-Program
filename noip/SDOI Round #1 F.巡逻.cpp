/*
1.Floyd������������˷��ĳ�Floyd��
һ����a���ľ����һ����b���ľ������Floyd���Եõ�һ����a+b���ľ���
���Կ������ñ�����������k����·��a����·���ߵ�Ȩֵ 
2.��ʼ��ע��߽�
3.�ֲ�ͼ˼�룺�����������·�ıߣ�����ת��ʱ��ɸ��ݵ���Ĳ���ȷ��Ȩֵ 
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
	for(int i = 1; i <= ans.n; i++) ans.val[i][i] = 0;//��Ϊ�˷�����ΪFloyd����i��i��ֵҪ��ֵΪ0 
	while (b){                                        //�������ܱ�֤ԭ�����ans������˴𰸲���� 
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
	matrix1.init(n * b + n);//������ʼ�� 
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
