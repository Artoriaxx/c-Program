#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
int a[maxn+5],g[maxn+5],f[maxn+5];//g�����¼������Ϊ��β����󶶶����ȣ�f���¼�½���~ 
int main()
{
	int n;
	cin>>n;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	f[1]=1;g[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])//���һ�������� 
		{
			f[i]=f[i-1];//��¼���½�Ϊ��β����������е�������ֵ����ǰһ�� 
			g[i]=max(f[i-1]+1,g[i-1]);//�����¼���һ������   ʲôʱ����Դ�g[i-1]ת�ƣ� �������ȥ������Ӱ��� 
		}
		if(a[i]==a[i-1])
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
		}
		if(a[i]<a[i-1])
		{
			f[i]=max(g[i-1]+1,f[i-1]);
			g[i]=g[i-1];
		}
	}
	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(g[i]>ans||f[i]>ans)
//		    ans=max(f[i],g[i]);
//	}
	cout<<max(f[n],g[n]);//��ʵ���һ���бض��������ֵ����Ϊf��g���鶼��ͳ�Ƶ���ǰ��� 
	return 0;
}
