#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int v0[65],w0[65],q[65],f[35000];
int v1[65],v2[65],w1[65],w2[65];
int main()
{
	memset(f,0,sizeof(f));
	int n,m,v,p,q;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v>>p>>q;
		if(q!=0)
		{
			if(v1[q]==0) 
			{
				v1[q]=v;w1[q]=p;
			}
			else
			{
				v2[q]=v;w2[q]=p;
			}
		}
		else
		{
			v0[i]=v;w0[i]=p;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)//À¦°ó×ªÒÆ 
		{
			if(j>=v0[i])
			    f[j]=max(f[j],f[j-v0[i]]+v0[i]*w0[i]);
			if(j>=v1[i]+v0[i])
			    f[j]=max(f[j],f[j-v0[i]-v1[i]]+v0[i]*w0[i]+v1[i]*w1[i]);
			if(j>=v2[i]+v1[i]+v0[i])
			    f[j]=max(f[j],f[j-v0[i]-v1[i]-v2[i]]+v0[i]*w0[i]+v1[i]*w1[i]+v2[i]*w2[i]);
		}
	}
	cout<<f[n];
	return 0;
}
