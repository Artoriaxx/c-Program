#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 200500;
int n,m;
long long s;
int w[N],v[N];
int zl[N],zr[N];
long long va[N],vb[N];
long long Abs(long long x)
{
	return (x<0?-x:x);
}
long long Calc(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		va[i]=va[i-1];
		vb[i]=vb[i-1];
		if(w[i]>=x)
		{
			va[i]++;
			vb[i]+=v[i];
		}
	}
	long long res=0;
	for(i=1;i<=m;i++)
		res+=(va[zr[i]]-va[zl[i]-1])*(vb[zr[i]]-vb[zl[i]-1]);
	return res;
}
int main()
{
	int i,j;
	scanf("%d%d%I64d",&n,&m,&s);
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d",&zl[i],&zr[i]);
	int l=0,r=1000001;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		long long now=Calc(mid);
		if(now>=s)
			l=mid;
		else
			r=mid-1;
	}
	long long ans=Abs(Calc(l)-s);
	ans=min(ans,Abs(Calc(l+1)-s));
	printf("%I64d\n",ans);
	return 0;
}
