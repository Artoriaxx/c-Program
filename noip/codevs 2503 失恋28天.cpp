#include<iostream>
#include<cstring>
using namespace std;
long long c[1500],w[1500],n[1500];//因为是拆完后的数量所以注意数组大小 
long long f[1500];
int main()
{
	memset(f,0,sizeof(f));
	int m,n,p,W,h;
	cin>>m>>n;
	int count=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>W>>h;
		for(int j=1;j<=h;j<<=1)
		{
			w[count]=j*p;
			c[count++]=j*W;
			h-=j;
		}
		if(h>0)
		{
			w[count]=h*p;
			c[count++]=h*W;
		}
	}
	for(int i=1;i<count;i++)
	{
		for(int j=m;j>=1;j--)//注意拆完之后是01背包 
		{
			if(j-w[i]>=0)
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
	}
	cout<<f[m];
	return 0;
}
