#include<iostream>
#include<cstring>
using namespace std;
long long a[3050],b[3050],f[3050][3050]//f[i][j]��¼��b[j]Ϊ��β�����������������;
int main()
{
	memset(f,0,sizeof(f));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int maxn;
	for(int i=1;i<=n;i++)
	{
		maxn=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])//��ȵĻ�����ӵ�֮ǰ���������������֮�󣬼����Լ� 
			{
				f[i][j]=maxn+1;
			}
			if(a[i]!=b[j])//�����ȣ���a[i]���������������Ӱ�죬��ǰһ��a[i]ת�� 
			{
				f[i][j]=f[i-1][j];
			}
			if(a[i]>b[j]&&f[i][j]>maxn)//���Ǽ���a[i]==b[j]ʱ��b[j]Ҫ�ӵ�������к�                           
			{                          //��Ҫ����b[j]>b[k](1<=k<=j-1),��maxn��¼��ʹ֮n^2���Ӷ� 
				maxn=f[i][j];
			}
		}
	}
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]>maxn)
			maxn=f[i][j];
		}
//		for(int j=1;j<=n;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
	}
	cout<<maxn;
	return 0;
}
