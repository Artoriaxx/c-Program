#include<iostream>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	string n;
	int m;
	cin>>n;
	cin>>m;
	for(int i=0;i<n.length();i++)
	{
		if(n[i]!='A'&&n[i]!='B'&&n[i]!='C'&&n[i]!='D'&&n[i]!='E'&&n[i]!='F')
		a[i]=n[i]-'0';
		else
		{
			switch(n[i])
			{
				case 'A': a[i]=10;break;
				case 'B': a[i]=11;break;
				case 'C': a[i]=12;break;
				case 'D': a[i]=13;break;
				case 'E': a[i]=14;break;
				default : a[i]=15;break;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n.length();i++)
	{
		if(a[i]==0)
		continue;
		else
		{
			ans+=a[i]*pow(m,n.length()-i-1);
		}
	}
	cout<<ans;
	return 0;
}
