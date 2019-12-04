#include<iostream>
using namespace std;
long long a[30],f[30][10050];//f数组记录选第i种货币组成价值为j的钱的种类 
int main()
{
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	{
		cin>>a[i];
		f[i][0]=1;//初始化选第i种钱币组成0元为1！！！ 
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j-a[i]>=0)//注意是否越界，若不越界，则为分为选或不选这种钱币两种 
			f[i][j]=f[i-1][j]+f[i][j-a[i]];
			else//上一种不能转移，种类数就等于不选这种钱币的种类数 
			f[i][j]=f[i-1][j];
		}
	}
	cout<<f[v][n];
	return 0;
}
