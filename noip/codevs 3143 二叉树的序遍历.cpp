#include<iostream>
using namespace std;
int l[20],r[20];
void pre(int n)//ǰ����� 
{
	cout<<n<<" ";
	if(l[n]>0) pre(l[n]);
	if(r[n]>0) pre(r[n]);
}
void mid(int n)//������� 
{
	if(l[n]>0) mid(l[n]);
	cout<<n<<" ";
	if(r[n]>0) mid(r[n]);
}
void last(int n)//������� 
{
	if(l[n]>0) hou(l[n]);
	if(r[n]>0) hou(r[n]);
	cout<<n<<" ";
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	pre(1);cout<<endl;
	mid(1);cout<<endl;
	hou(1);
	return 0;
}
