#include<iostream>
using namespace std;
int a[500],f[500][500];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];//������ģ�⻷����������Ҫö�ٴӺδ��Ͽ� 
	}
	for(int l=1;l<=n-1;l++)//��ʵ��������dp��û��ô���� 
	{
		for(int i=1;i<=2*n-l-1;i++)
		{
			int j=i+l;
			for(int k=i;k<=j-1;k++)
			{
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)//���ڴ��ĸ��ϵ�Ͽ���һ����
	{	                 //����Ҫ��1��n�ҶϿ�����ֵ 
		ans=max(ans,f[i][i+n-1]);
	}
	cout<<ans;
	return 0;
}
