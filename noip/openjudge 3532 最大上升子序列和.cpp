#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1050],f[1050];
int z;
int main()
{
	memset(f,0,sizeof(f));
	int n,b=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=a[1];

	for(int i=2;i<=n;i++)
	{
		z=0;
		for(int j=1;j<i;j++)
		{
			if(f[j]>z&&a[i]>a[j])
			    z=f[j];
		}
		f[i]=z+a[i];
	}
//	for(int i=1;i<=n;i++)
//		cout<<i<<" "<<f[i]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>b)
		b=f[i];
	}
	cout<<b;
	return 0;
}
