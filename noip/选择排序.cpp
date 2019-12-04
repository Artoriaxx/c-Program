#include<iostream>
#include<iomanip>
using namespace std;
int t,a[11];
int main()
{
	cout<<"Input 10 intergers:"<<endl;
	for(int i=1;i<=10;i++) cin>>a[i];
	cout<<endl;
	for(int i=1;i<=9;i++)
	  for(int j=i+1;j<=10;++j)
	    if(a[i]<a[j]) {t=a[i];a[i]=a[j];a[j]=t;}
	for(int i=1;i<=10;i++)
	  cout<<setw(5)<<a[i];
	return 0;
}
