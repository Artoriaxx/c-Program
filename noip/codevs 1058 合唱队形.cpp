#include<cstdio>
#include<cstring>
using namespace std;
int a[150],f[150],g[150];
int main()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f[1]=1;g[n]=1; 
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]>a[j]&&f[j]>f[i])
			f[i]=f[j];
		}
		f[i]++;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]&&g[j]>g[i])
			g[i]=g[j];
		}
		g[i]++;
	}
	int maxl=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]+g[i]>maxl)
		maxl=f[i]+g[i];
	}
	printf("%d",n-maxl+1);
}
