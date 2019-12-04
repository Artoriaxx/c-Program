#include<iostream>
#include<cstring>
using namespace std;
long long c[50050],f[50050],s[50050];
int deq[50050];
double qiuk(int i,int j)
{
	return (1.0*(f[i]+s[i]*s[i]-f[j]-s[j]*s[j])/(s[i]-s[j]));
}
int main()
{
	memset(f,0,sizeof(f));
	memset(deq,0,sizeof(deq));
	int n,L;
	cin>>n>>L;
	c[0]=0;s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]+=c[i-1];s[i]=c[i]+i;
	}
	f[0]=0;deq[0]=0;
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		long long x=s[i]-L-1;
		while(l<r&&qiuk(deq[l+1],deq[l])<=2*x)
		l++;
		int j=deq[l];
		f[i]=f[j]+(x-s[j])*(x-s[j]);
		while(l<r&&qiuk(deq[r],deq[r-1])>=qiuk(i,deq[r]))
		r--;
		deq[++r]=i;
	}
	cout<<f[n];
	return 0;
}
