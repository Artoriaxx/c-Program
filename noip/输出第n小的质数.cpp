#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int n,m=0,a=0;
	cin>>n;
	for(int i=2;i<=110000;i++)
	{
		a=0;
		for(int j=2;j<=sqrt(i);j++)
		{
		    if(i%j==0) 
		    {
		    a++;
		    break;
		    }
		}
    if(a==0) m++;
    if(m==n) 
    {
    cout<<i;
    break;
    }			 
    }
    return 0;
}

