#include<iostream>
using namespace std;
int a[120],b[120];
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int avg=sum/n,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>avg)
		{
			a[i+1]+=a[i]-avg;
			cnt++;
		}
		if(a[i]<avg)
		{
			a[i+1]-=avg-a[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
