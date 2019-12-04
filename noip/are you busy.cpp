#include<iostream>
using namespace std;
int ci[150][150],gi[150][150],f[150][150];
int main()
{
	int n,t;
	while(cin>>n>>t)
	{
		int m,s;
		for(int i=1;i<=n;i++)
		{
			cin>>m>>s;
			for(int j=1;j<=m;j++)
			{
				cin>>ci[i][j]>>gi[i][j];
			}
		}
		if(s==1)
		{
			for(int i=1;i<=n;i++)
		    {
			    for(int v=t;v>=0;v--)
			    {
				    for(int k=1;k<=m;k++)
				    {
					    f[i][v]=max(f[i-1][v],f[i-1][v-ci[i][k]]+gi[i][k]);
				    }
			    }
		    }
		}
		if(s==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int k=1;k<=m;k++)
				{
					for(int v=t;v>=ci[i][k];v--)
					{
						f[i][v]=max(f[i-1][v],f[i-1][v-ci[i][k]]+gi[i][k]);
					}
				}
			}
		}
		if(s==-1)
		{
			
		}
	}
}
