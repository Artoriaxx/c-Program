#include<iostream>
using namespace std;
int gcd(int a,int b)//�����Լ�� 
{
	return a%b==0?b:gcd(b,a%b);
}
int main()
{
	int n,m;cin>>n>>m;
	cout<<gcd(n,m);
	return 0;
} 
