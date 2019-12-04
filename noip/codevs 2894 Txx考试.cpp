#include<iostream>
using namespace std;
int f[100005],p[505],t[505];
int main()
{
	int k,n;
	cin>>k>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>p[i];
		sum+=p[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j>=t[i];j--)
		{
			f[j]=max(f[j],f[j-t[i]]+p[i]);
		}
	}
	cout<<sum-f[k];
	return 0;
}
