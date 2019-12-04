#include<iostream>
#include<cstring>
using namespace std;
char a[150][150];bool vis[150][150];
int dir1[4]={-1,1,0,0};
int dir2[4]={0,0,-1,1};
int u,v;
int ans;
void dfs(int x,int y)
{
	vis[x][y]=true;
	ans++;
	if(a[x][y]=='W'||a[x][y]==0)
	    return ;
	for(int i=0;i<4;i++)
	{
		u=x+dir1[i];
		v=y+dir2[i];
		if(!vis[u][v]&&a[u][v]=='.')
		    dfs(u,v);
		else
		    continue;
	}
}
int main()
{
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	if(a[i][j]=='B'&&!vis[i][j])
	    	    dfs(i,j);
		}
	
	cout<<ans<<" "<<n*n-ans;
	return 0;
}
