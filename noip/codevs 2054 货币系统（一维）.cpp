#include<iostream>
using namespace std;
long long a[30],f[10050];
int main()
{
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=v;i++)
		cin>>a[i];
	f[0]=1;
	for(int i=1;i<=v;i++)
	{
		for(int j=a[i];j<=n;j++)
		{
			f[j]=f[j]+f[j-a[i]];//��ת��Ϊһά,f[j]�൱����һ�� 
		}
	}
	cout<<f[n];
	return 0;
}
