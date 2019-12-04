#include<iostream>
#include<cstdio>
using namespace std;
int a[5001];
int main()
{
	int n,m,first=1;
	cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
      for(int s=1;s<=m;s++)
        if(s%i==0) a[s]=!a[s];
    } 
    for(int i=1;i<=m;i++)
    if(a[i])
    {
    	if(first) first=0;
    	else cout<<",";
    	cout<<i;
    }
    return 0;
}
