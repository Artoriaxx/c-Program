#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<cstdio>
using namespace std;
int a[17];
int main(){
a[0]=0;
int s=0;
for(int i=1;i<=16;i++) {
a[i]=pow(2,i-1);
s+=a[i];}
cout<<s;
getchar();
return 0;
}
