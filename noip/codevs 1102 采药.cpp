#include<iostream>
#include<cstring>
using namespace std;
int w[105],c[105],f[1050];
int main()
{
	memset(f,0,sizeof(f));
	int v,n;
	cin>>n>>v;
	for(int i=1;i<=v;i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(j-w[i]>=0)
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
	}
	cout<<f[n];
	return 0;
}
