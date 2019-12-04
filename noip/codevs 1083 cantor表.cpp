#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a=1,b=1;int k=2;
	for(int i=1;i<=n-1;i++)
	{
		if(k%2==0)
		{
			if(a==1)
			{
				k++;
				b=k-1;
				continue;
			}
			else
			{
				a--;
				b++;
			}
		}
		if(k%2==1)
		{
			if(b==1)
			{
				k++;
				a=k-1;
				continue;
			}
			else
			{
				a++;
				b--;
			}
		}
	}
	cout<<a<<"/"<<b;
}
