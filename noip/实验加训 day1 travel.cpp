/*
Cij=��Aik+Bkj (1<=k<=n,n�Ǿ����С)  ע��i��ʾ�У�j��ʾ��

*/
#include<iostream>
#include<cstring>
#define p 998224353
#define s 21
using namespace std;
struct matrix{
	long long val[s][s]; 
	//����һ����λ���󣬳�������������������ֵ���� 
	void build(){ 
		memset(val, 0, sizeof(val));
		for(int i = 0; i < s; i++)
			val[i][i] = 1;
	}
	
	void init(){
		memset(val, 0, sizeof(val));
	}
	//���¶������˷� 
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
//��������� 
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
			if(j > 0) x.val[j][j - 1] = 1;//�����������ע��߽� 
			if(j < y) x.val[j][j + 1] = 1;//����̬�滮 
		}
		if(b > k) b = k;//����Ŀ�ĵر߽�Ͱ�Ŀ�ĵ����� 
		matrix c = fastpow(x, b - a);//����������b - a��ת�� 
		memset(now, 0, sizeof(now));
		for(int i = 0; i < s; i++){
			for(int j = 0; j < s; j++){
				(now[i] += ans[j] * c.val[i][j] % p) %= p;//��now�����¼ת�� 
			}
		}
		for(int i = 0; i < s; i++){
			ans[i] = now[i] % p;//��now���� % p����ans��ת����һ�� 
		}
	}
	cout<<ans[0];//ans[0]��Ϊ�� 
	return 0;
}
