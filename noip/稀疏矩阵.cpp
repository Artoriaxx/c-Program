#include<iostream>
#include<iomanip>
const int n=3,m=5;
using namespace std;
int main()
{
int    a[n+1][m+1],b[46][4],k=0;
for (int i=1; i<=n; ++i)       
for (int j=1; j<=m; ++j) 
cin>>a[i][j];
for (int i=1; i<=n; ++i)
for (int j=1; j<=m; ++j)
if (a[i][j]!=0)    
{
++k;
b[k][1]=i;
b[k][2]=j;
b[k][3]=a[i][j];
}
for (int i=1; i<=k; ++i)     
{
for (int j=1; j<=3; ++j) 
cout<<setw(3)<<b[i][j];
cout<<endl;
}
return 0;
}
