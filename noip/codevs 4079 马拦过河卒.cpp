#include<iostream>
#include<cstring>
using namespace std;
int a[25][25];
int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=0;i<=n;i++)
	    for(int j=0;j<=m;j++)
	    {
	    	a[i][j]=1;
		}
	a[x-1][y-2]=0;a[x-2][y-1]=0;a[x+2][y-1]=0;a[x+1][y-2]=0;
	a[x-1][y+2]=0;a[x-2][y+1]=0;a[x+2][y+1]=0;a[x+1][y+2]=0;
	a[x][y]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	if(a[0][1]==0&&a[1][0]==0)//若第一步无法走，则为0 
	{
		cout<<0;
	    return 0;
	}
	cout<<a[n][m];
	return 0;
}
