#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct xuan
{
	int iq,eq;
}a[1050];
bool cmp(xuan x,xuan y)
{
	if(x.iq>y.iq)
	return 1;
	else return 0;
}
int f[1050];
int main()
{
	memset(f,0,sizeof(f));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].iq;
		cin>>a[i].eq;
	}
	sort(a+1,a+n+1,cmp);
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j].eq>=a[i].eq&&f[j]>f[i])
			f[i]=f[j];
		}
		f[i]++;
	}
	int z=0;
	for(int i=1;i<=n;i++)
	{
		
		if(f[i]>z)
		z=f[i];
	}
	cout<<z;
}
