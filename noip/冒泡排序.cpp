#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
const int n=10;
int t,a[n+1];
int main()
{
	cout<<"Input 10 intergers:"<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<endl;
	for(int j=1;j<=n-1;j++)
	  for(int i=1;i<=n-j;i++)
	    if(a[i]<a[i+1])
	      {t=a[i];a[i]=a[i+1];a[i+1]=t;}
    for(int i=1;i<=n;i++)
      printf("%d ",a[i]);
    cout<<endl;
    return 0;
}
