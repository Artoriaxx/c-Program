#include<iostream>
using namespace std;
int w[100],c[100];int f[600];
int main()
{
	int n,m,q;
	int count=0;
	cin>>n>>m>>q;
	int wl,cl,c1l;
	for(int i=1;i<=n;i++)
	{
		cin>>wl>>cl>>c1l;
		if(c1l<=q)
		{
			count++;
			w[count]=wl;
			c[count]=cl;
		}
	}
	for(int i=1;i<=count;i++)
	{
		for(int j=m;j>=c[i];j--)
		{
				f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
	}
	cout<<f[m];
	return 0;
}
