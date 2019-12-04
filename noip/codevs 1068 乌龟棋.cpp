#include<iostream>
using namespace std;
int a[400],b[5],f[51][51][51][51];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int q;
	for(int i=1;i<=m;i++)
	{
		cin>>q;
		b[q]++;
	}
	f[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)
		for(int j=0;j<=b[2];j++)
			for(int x=0;x<=b[3];x++)
				for(int y=0;y<=b[4];y++)
				{
					int num=a[1+i+2*j+3*x+4*y];
					if(i) f[i][j][x][y]=max(f[i][j][x][y],f[i-1][j][x][y]+num);
					if(j) f[i][j][x][y]=max(f[i][j][x][y],f[i][j-1][x][y]+num);
					if(x) f[i][j][x][y]=max(f[i][j][x][y],f[i][j][x-1][y]+num);
					if(y) f[i][j][x][y]=max(f[i][j][x][y],f[i][j][x][y-1]+num);
				}
	cout<<f[b[1]][b[2]][b[3]][b[4]];
	return 0;
}
