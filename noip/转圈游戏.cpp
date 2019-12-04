#include<iostream>
#include<math.h>
using namespace std;
int T;
int GCD(int x,int y)
{
	int b;
	while(x%y!=0)
	{
		b=x%y;
		x=y;
		y=b;
	}
	return y;
}
int fast_pow(int a,int p)
{
	int ans=1;
	for(;p;p>>=1,a=a*a%T)
	    if(p&1)
	    ans = (ans%T * a%T)%T;
	return ans;
}
int main()
{
	int n,m,k,x;
	cin>>n>>m>>k>>x;

	if(n%m==0)
	{
		T=n/m;
	}
	else
	{
		if(GCD(n,m)==1)
		T=n;
		else
		T=n/GCD(n,m);
	}
	int z=fast_pow(10,k);
	x=(x+(z%T*m)%n)%n;
	cout<<x;
	return 0;
}
