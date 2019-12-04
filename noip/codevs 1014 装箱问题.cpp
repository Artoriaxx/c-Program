#include<iostream>
using namespace std;
int a[35],f[25000];
int main()
{
	int n,v;
	cin>>v>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=v;j>=a[i];j--)
		{
			if(f[j-a[i]])
			f[j]=1;
		}
	}
	for(int j=v;j>=0;j--)
	{
		if(f[j]==1)
		{
			cout<<v-j;
			return 0;
		}
	}
}
