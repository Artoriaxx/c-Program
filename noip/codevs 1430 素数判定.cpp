#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) sum++;
	}
	if(n==2) cout<<"\\t";
	else if(sum>0) cout<<"\\n";
	else cout<<"\\t";
	return 0;
}
