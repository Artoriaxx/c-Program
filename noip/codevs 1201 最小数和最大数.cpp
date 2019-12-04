#include<iostream>
using namespace std;
int main()
{
	int min=0x3f3f3f3f;
	int max=-0x3f3f3f3f+1;
	long long n,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s<min)
		{
			min=s;
		}
		if(s>max)
		{
			max=s;
		}
	}
	cout<<min<<" "<<max;
}
