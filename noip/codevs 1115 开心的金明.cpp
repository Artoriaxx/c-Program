#include<iostream>
#include<cstring>
using namespace std;
int v0[30],w0[30],f[35000];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v0[i]>>w0[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(j-v0[i]>=0)
			f[j]=max(f[j],f[j-v0[i]]+v0[i]*w0[i]);
		}
	}
	cout<<f[n];
	return 0;
} 

