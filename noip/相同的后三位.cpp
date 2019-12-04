#include<iostream>
#define maxn 1001
#define maxm 10000000000000
using namespace std;
long long  a[maxn];
int fast_pow(long long a,int p)
{
	long long ans=1;
	for(; p ; p >>= 1, a = a*a%1000 )// 要在此处%1000，否则会爆  
		if( p & 1 )
		    ans = ((ans%1000) * (a%1000))%1000;
	return ans;
}
int main()
{
	int n=maxm,m=maxm,p;
	cin>>p;
	for(int i=1;i<=maxn;i++)
	    a[i]=fast_pow(p,i);
	for(int i = 1 ; i <= maxn ; i++)
	    for(int j = 1;j <= maxn; j++)
			if(a[j]==a[i]&& j>i)
	        {
			   if(j<m)
			   {
			   	   m=j;
			   	   n=i;
			   }
	        }
	cout<<m<<" "<<n;
	return 0;
}
