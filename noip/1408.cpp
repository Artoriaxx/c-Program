#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3050],b[3050],f[3050][3050];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	memset(f,0,sizeof(f));
	int ans=0,maxl;
	for(int i=1;i<=n;i++)
	{
	    maxl=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
			{
				f[i][j]=maxl+1;
			}
			if(a[i]!=b[j])
			{
				f[i][j]=f[i-1][j];
			}
			if(a[i]>b[j])
			maxl=max(maxl,f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
}
