#include<iostream>
#include<cstdio>
#define inf 1000000
using namespace std;
int a[150][150],ans,k;
int d[150];
bool f[150];
int main()
{
	int n,min;
	cin>>n;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	cin>>a[i][j];
	    }
	        
	
	for(int i=1;i<=n;i++)
	{
		d[i]=a[1][i];
		f[i]=false;
	}
	f[1]=true;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		min=inf;
		for(int j=1;j<=n;j++)
	    {
	    	if((!f[j])&&d[j]<min&&a[i][j]!=0)
	    	{
	    		min=d[j];
	    		k=j;
	    	}
	    }
		f[k]=true;
	    for(int m=1;m<=n;m++)
	    {
	    	if((!f[m])&&a[k][m]<d[m]&&a[k][m]!=0)
	    	d[m]=a[k][m];
	    }
	}
	for(int i=1;i<=n;i++)
	ans+=d[i];
	cout<<ans;
	return 0;
}
