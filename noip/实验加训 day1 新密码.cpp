#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	long long point=sqrt(a);
	long long ans=0;
	if(a>b) 
	{
		ans+=b*(a-b);
		a=b;
	}
	while(a>point)
	{
		int l=b%a;int t=b/a;int last=a;
		a=b/(t+1);int r=b%(a+1);
		ans+=(l+r)*(last-a)/2;
	}
	for(int i=1;i<=a;i++)
	{
		ans+=b%i;
	}
	cout<<ans;
	return 0;
}
