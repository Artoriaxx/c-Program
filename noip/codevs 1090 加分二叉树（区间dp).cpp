//״̬ת�Ʒ��̣�
//f[i,j]=max{f[i,k-1]*f[k+1,j]+a[k]}  (i<k<j)��
//��ʼ��
//f[i,i]=a[i];  f[i,j]=1;
//Ŀ�꣺f[1,n]
#include<iostream>
using namespace std;
int root[35][35];//root[i][j]��ʾ����i��j֮��ĸ� 
long long f[35][35],a[35];
void visit(int i,int j)//���i��j������������ 
{
	if(i<=j)
	{
		cout<<root[i][j]<<" ";
		visit(i,root[i][j]-1);
		visit(root[i][j]+1,j);//�ݹ�Ѱ�� 
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n+1;i++)//��0��ʼö�٣���̬ת�Ʒ����г�����0 
	{
		for(int j=0;j<=n+1;j++)//����1�������ڶ˵����Ϊ���ڵ㣬��ʱ 
		{                      //����Ӧ��Ϊ��/������*1+������������԰�f��ֵΪ1 
			f[i][j]=1;
		}
	}
		for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];//Ҷ�ӽڵ�ĸ�ֵΪ������� 
		root[i][i]=i;//һ���ڵ�ĸ��ڵ�Ϊ�Լ� 
	}
	for(int l=1;l<=n-1;l++)//�����ѭ��ö�����䳤�� 
	{
		for(int i=1;i<=n-l;i++)//ö����� 
		{
			int j=i+l;//���ӳ���Ϊ�յ� 
			for(int k=i;k<=j;k++)//ö���м�� 
			{
				if(f[i][j]<f[i][k-1]*f[k+1][j]+a[k])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];//��һ�����������ļӷ� 
					root[i][j]=k;//��һ�����ڵĸ� 
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	visit(1,n);
	return 0;
}
