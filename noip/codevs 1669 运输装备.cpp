#include<iostream>
#include<cstring>
using namespace std;
int w[1050],vl[1050],gl[1050],f[1050][1050];
int main()
{
	memset(f,0,sizeof(f));
	int v,g;
	cin>>v>>g;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>vl[i]>>gl[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=g;j>=gl[i];j--)
		{
			for(int k=v;k>=vl[i];k--)
			{
				f[j][k]=max(f[j][k],f[j-gl[i]][k-vl[i]]+w[i]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=g;i++)
	{
		for(int j=1;j<=v;j++)
		{
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
}
