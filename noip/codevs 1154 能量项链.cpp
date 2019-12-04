#include<iostream>
using namespace std;
int a[500],f[500][500];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];//用数组模拟环，这样不需要枚举从何处断开 
	}
	for(int l=1;l<=n-1;l++)//其实就是区间dp，没那么复杂 
	{
		for(int i=1;i<=2*n-l-1;i++)
		{
			int j=i+l;
			for(int k=i;k<=j-1;k++)
			{
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)//由于从哪个断点断开不一样，
	{	                 //所以要从1到n找断开最大的值 
		ans=max(ans,f[i][i+n-1]);
	}
	cout<<ans;
	return 0;
}
