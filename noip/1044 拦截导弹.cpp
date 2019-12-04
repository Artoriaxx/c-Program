#include<iostream>
#include<cstring>
using namespace std;
int a[25],f[25];
int main()
{
	memset(f,0,sizeof(f));
    int n=1,b;
    while(cin>>a[n])
    {
    	n++;
    }
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>=a[i]&&f[j]>f[i]&&a[i]!=0)
			    f[i]=f[j];
		}
		f[i]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>ans)
	    ans=f[i];
	}
	cout<<ans<<endl;
	memset(f,0,sizeof(f));//最长上升子序列=不上升子序列的最小划分数
	ans=0;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i]&&f[j]>f[i])
			    f[i]=f[j];
			
		}
		f[i]++;
	}	
	for(int i=1;i<=n;i++)
	{
		if(f[i]>ans)
	    ans=f[i];
	}
	cout<<ans;
	return 0;
}
