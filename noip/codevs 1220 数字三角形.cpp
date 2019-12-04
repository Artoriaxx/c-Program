#include<iostream>
using namespace std;
int a[105][105],f[105][105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=max(f[i-1][j]+a[i][j],f[i-1][j-1]+a[i][j]);
		}
	}
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}
