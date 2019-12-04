#include<iostream>
using namespace std;
int f[150][150],sum[150];
int main()
{
	int n,a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum[i]=sum[i-1]+a;
	}
	for(int l=1;l<=n-1;l++)
	{
		for(int i=1;i<=n-l;i++)
		{
			int j=i+l;
			f[i][j]=0x3f3f3f3f;
			for(int k=i;k<=j;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
