#include<iostream>
using namespace std;
int c[205],w[205],z[205],nl[50000],cl[50000],wl[50000];
int f[200005];
int main()
{
	int n,v;
	cin>>n>>v;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>w[i]>>z[i];
	int count=0;
	for(int i=1;i<=n;i++)//����һ���㶼�����ˣ�ȫ��tle... 
	{
		if(z[i]==1||z[i]==-1)
		continue;
		else
		{
			for(int j=1;j<=z[i];j<<=1)
			{
				count++;
				cl[count]=j*c[i];
				wl[count]=j*w[i];
				z[i]-=j;
			}
			if(z[i]>0)
			{
				count++;
				cl[count]=z[i]*c[i];
				wl[count]=z[i]*w[i];
			}
			if(z[i]==-1||z[i]==1)//�������ʣ����1��-1��Ӱ���ж� 
			{
				z[i]='#';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(z[i]==1)
		{
			for(int j=v;j>=c[i];j--)
			{
				f[j]=max(f[j],f[j-c[i]]+w[i]);
			}
		}
		if(z[i]==-1)
		{
			for(int j=c[i];j<=v;j++)
			{
				f[j]=max(f[j],f[j-c[i]]+w[i]);
			}
		}
	}
	for(int i=1;i<=count;i++)//���ر���������һ��ѭ�� 
	{
		for(int j=v;j>=cl[i];j--)
		{
			f[j]=max(f[j],f[j-cl[i]]+wl[i]);
		}
	}
	cout<<f[v];
	return 0;
}
