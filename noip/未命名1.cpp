#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[105][105],f[105];
int n,m;
int main()
{
	
	while(scanf("%d%d",&n,&m)&&n+m)
	{
		memset(f,0,sizeof(f));
	    for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		scanf("%d",&a[i][j]);
	    	}
	    }
	    for(int i=1;i<=n;i++)
	    {
	    	for(int v=m;v>=0;v--)
	    	{
	    		for(int k=1;k<=m;k++)
	    		{
	    			if(v-k>0)
	    			f[v]=max(f[v],f[v-k]+a[i][k]);
	    		}
	    	}
	    }
	    printf("%d\n",f[m]);
	}
	return 0;
}
