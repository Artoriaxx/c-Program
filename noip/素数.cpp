#include<iostream>
#include<math.h>    
#include<iomanip>
using namespace std;
const int n=100;
int t;
bool a[n+1];
int main()
{
for (int i=0; i<=n; i++) a[i]=true;               
for (int i=2; i<=sqrt(n); ++i)
for (int j=2; j<=n/i; ++j)
a[i*j]=false;
t=0;
for (int i=2; i<=n; ++i)
if (a[i]) 
{
cout<<setw(5)<<i;
t++;
if (t%5==0) cout<<endl;
}
return 0;
}

