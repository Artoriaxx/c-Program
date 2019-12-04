#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std; 
const int N = 100500;
int a[N],b[N],c[N];
char e[N];
int xu[N],cc;
int n;
int fa[N],val[N];
bool cmp(int x,int y)
{
	if(x<y)
		return true;
	else
		return false;
}
int Find(int t)
{
	int l=1,r=cc;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(xu[mid]==t)
			return mid;
		if(xu[mid]<t)
			l=mid+1;
		if(xu[mid]>t)
			r=mid-1;
	}
}
int getf(int x)
{
	if(fa[x]!=x)
	{
		int f=getf(fa[x]);
		val[x]^=val[fa[x]];
		fa[x]=f;
	}
	return(fa[x]);
}
int f(int x)
{
	int la,lb;
	la=getf(a[x]);
	lb=getf(b[x]);
	if(la!=lb)
	{
		fa[la]=lb;
		val[la]=c[x]^val[a[x]]^val[b[x]];
		return 1;
	}
	if(val[a[x]]^val[b[x]]==c[x])
		return 1;
	return 0;
}
int main()
{
	int i;
	scanf("%*d%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%s",&a[i],&b[i],&e);
		if(e[0]=='e')
			c[i]=0;
		else
			c[i]=1;
	}
	for(i=1;i<=n;i++)
		a[i]=a[i]-1;
	for(i=1;i<=n;i++)
		xu[i]=a[i];
	for(i=1;i<=n;i++)
		xu[i+n]=b[i];
	sort(xu+1,xu+2*n+1,cmp);
	for(i=1;i<=2*n;i++)
	{
		cc=cc+1;
		xu[cc]=xu[i];
		while(i<2*n && xu[i]==xu[i+1])
			i=i+1;
	}
	for(i=1;i<=n;i++)
	{
		a[i]=Find(a[i]);
		b[i]=Find(b[i]);
	}
	for(i=1;i<=cc;i++)
		fa[i]=i;
	for(i=1;i<=n;i++)
	{
		if(f(i)==0)
			break;
	}
	i--;
	printf("%d\n",i);
	return 0;
}
