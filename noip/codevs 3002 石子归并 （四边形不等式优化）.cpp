//1.如果对于任意的a1≤a2<b1≤b2，有m[a1,b1]+m[a2,b2]≤m[a1,b2]+m[a2,b1]
//那么m[i,j]满足四边形不等式
//2. m[i,j]<=m[i',j']   ([i,j]属于[i',j']) 既 i'<=i<j<=j' 
//3.满足以上，则定义s(i,j)为函数m(i,j)对应的使得m(i,j)取得最大值的k值,则s[i,j-1]≤s[i,j]≤s[i+1,j]
#include<iostream>
#include<cstring>
using namespace std;
int v[3500][3500],f[3500][3500],sum[3500],a[3500];
int main()
{
	sum[0]=0;
	int n,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		v[i][i]=i;//用于优化 
		f[i][i]=0;
	}
	for(int p=1;p<=n-1;p++)//简单的区间dp 
	{
		for(int i=1;i<=n-p;i++)
		{
			int j=i+p;
			f[i][j]=0x3f3f3f3f;//别忘了把f数组初始为最大！ 
			for(int k=v[i][j-1];k<=v[i+1][j];k++)//运用四边形不等式降低一维复杂度 
			{
				if(f[i][j]>f[i][k]+f[k+1][j]+sum[j]-sum[i-1])
				{
					f[i][j]=f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
					v[i][j]=k;
				}
			} 
		}
	}
	cout<<f[1][n];
	return 0;
}
