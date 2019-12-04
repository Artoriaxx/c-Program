#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int i=1;
void mov(int n,char a,char c)
{
	cout<<n<<" from "<<a<<" to "<<c<<endl;
}
void haoni(int n,char a,char b,char c){
	if(n!=1) haoni(n-1,a,c,b);
	mov(n,a,c);
	if(n!=1) haoni(n-1,b,a,c);
}
int main()
{
	int n;
	cin>>n;
	char a='A',b='B',c='C';
	cout<<pow(2,n)-1<<endl;
	haoni(n,a,b,c);
	return 0;
}
