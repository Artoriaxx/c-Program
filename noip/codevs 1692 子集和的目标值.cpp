#include<iostream>
#include<cmath>
using namespace std;
long long a[150],ans=1e18,min1=1e18,f[2000005];
int n;long long t;
void dfs(int x,long long tot)
{
	if(x==n+1)
	{
		long long s=abs(t-tot);
		ans=min(ans,s);
		return; 
	}
	dfs(x+1,tot);
	dfs(x+1,tot+a[x]);
}
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		min1=min(min1,a[i]);
	}
	if(n<=20)//如果n很小则dfs 
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)//n大的时候数据很水 
	{
		for(long long j=2*t;j>=a[i];j--)
		{
			f[j]=f[j-a[i]]+a[i];
		}
	}
	for(long long i=1;i<=2*t;i++)
	{
		long long s=abs(f[i]-t);
		ans=min(ans,s);
	}
	if(!t) ans=min1;
	cout<<ans;
	return 0;
}
