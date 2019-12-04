#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
	{
	    int j=0;
		if(a[i]==b[0])
		{
			for(j=0;j<b.length();j++)
			{
				if(a[i+j]!=b[j]) break;
			}
		}
		if(j==b.length())
		{
			cout<<i+1;
			return 0;
		}
	}
}
