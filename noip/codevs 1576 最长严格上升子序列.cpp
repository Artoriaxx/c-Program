#include<iostream>
using namespace std;
int a[5500],f[5500];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j])
			f[i]=max(f[i],f[j]);
		}
		f[i]+=1;
	}
	cout<<f[n];
	return 0;
}
