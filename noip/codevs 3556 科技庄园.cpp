#include<iostream>
#include<cstring>
using namespace std;
long long a[105][105],b[105][105],c[100000],w[100000],f[100000],z[100000],cl[100000],wl[100000];
int main()//����Ĵ�СҪע�⣬����Ķ�cl��wl��fҪ������10^5��Ϊ100^2*7(n*m*k) 
{
	long long n,m,ti,A;
	cin>>n>>m>>ti>>A;
	long long v=min(ti,A-1);
	long long sumn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];//ע��һ��ʼҪ�ö�ά����������ֱ�����봦�� 
		}                //��ΪҪ�ж��������Ͳ�ժ������ͬʱΪ0����� 
	}                    //����ͬʱΪ0����ʱҲ�ǲ����ϵ� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0&&b[i][j]!=0)//��ͬʱΪ0�������ݴ��� 
			{
				sumn++;//��¼�ж��ٺϷ��� 
				c[sumn]=a[i][j];
				w[sumn]=2*(i+j);//����ע�����أ�����Ҫ��2 
				z[sumn]=b[i][j];
			}
		}
	}
//	cout<<sumn;
	long long count=0;
//	int u=0;
//	for(int i=1;i<=sumn;i++)
//	{
//		u+=z[i]*c[i];
//	}
	for(int i=1;i<=sumn;i++)//��ⱳ�� 
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
	}
//	for(int i=1;i<count;i++)
//	cout<<cl[i]<<" "<<wl[i]<<endl;
    f[0]=0;
	for(int i=1;i<=count;i++)
	{
		for(int j=v;j>=wl[i];j--)
		{
			f[j]=max(f[j],f[j-wl[i]]+cl[i]);//��������01���� 
		}
	}
	cout<<f[v];
	return 0;
}
