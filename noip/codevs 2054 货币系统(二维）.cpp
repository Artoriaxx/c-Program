#include<iostream>
using namespace std;
long long a[30],f[30][10050];//f�����¼ѡ��i�ֻ�����ɼ�ֵΪj��Ǯ������ 
int main()
{
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	{
		cin>>a[i];
		f[i][0]=1;//��ʼ��ѡ��i��Ǯ�����0ԪΪ1������ 
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j-a[i]>=0)//ע���Ƿ�Խ�磬����Խ�磬��Ϊ��Ϊѡ��ѡ����Ǯ������ 
			f[i][j]=f[i-1][j]+f[i][j-a[i]];
			else//��һ�ֲ���ת�ƣ��������͵��ڲ�ѡ����Ǯ�ҵ������� 
			f[i][j]=f[i-1][j];
		}
	}
	cout<<f[v][n];
	return 0;
}
