#include<iostream>
#include<cstdio>
#define maxn 200050
using namespace std;
long long sum[maxn];long long a[maxn];
int main()
{
//	freopen("cuisine.in","r",stdin);
//	freopen("cuisine.out","w",stdout);
	int n;
	long long p,q;
	long long l;
	long long r;
	long long mid,tmp,vis1,vis2;
	scanf("%d%lld%lld",&n,&p,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	bool flag1=0; bool flag2=0;
	for(int i=1;i<=n;i++)
	{
		l=i+1;r=n;
		flag1=0;flag2=0;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			tmp=sum[mid]-sum[i-1];
			
			if(tmp==p) 
			{
				vis1=mid;
				flag1=1;
				break;
			}
			else if(tmp>p)
			{
		     	vis1=mid;
		     	flag1=1;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		l=i+1;r=n;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			tmp=sum[mid]-sum[i-1];
			if(tmp==q) 
			{
				vis2=mid;
				flag2=1;
				break;
			}
			else if(tmp<q)
			{
				vis2=mid;
				flag2=1;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		if(flag1&&flag2) ans+=vis2-vis1+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=p&&a[i]<=q) ans++;
	}
	printf("%lld",ans);
	return 0;
}
