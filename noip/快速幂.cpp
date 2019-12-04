#include<iostream>
using namespace std;
int fast_pow(int a,int p)
{
	int ans=1;
	for(;p;p>>=1,a=a*a)
	    if (p&1)
	        ans=ans*a;
	return ans;
}
int main()
{
	int a,p;
	cin>>a>>p;
	cout<<fast_pow(a,p);
	return 0;
}
