//1.������������a1��a2<b1��b2����m[a1,b1]+m[a2,b2]��m[a1,b2]+m[a2,b1]
//��ôm[i,j]�����ı��β���ʽ
//2. m[i,j]<=m[i',j']   ([i,j]����[i',j']) �� i'<=i<j<=j' 
//3.�������ϣ�����s(i,j)Ϊ����m(i,j)��Ӧ��ʹ��m(i,j)ȡ�����ֵ��kֵ,��s[i,j-1]��s[i,j]��s[i+1,j]
#include<iostream>
#include<cstring>
using namespace std;
int v[3500][3500],f[3500][3500],sum[3500],a[3500];
int main()
{
	sum[0]=0;
	int n,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		v[i][i]=i;//�����Ż� 
		f[i][i]=0;
	}
	for(int p=1;p<=n-1;p++)//�򵥵�����dp 
	{
		for(int i=1;i<=n-p;i++)
		{
			int j=i+p;
			f[i][j]=0x3f3f3f3f;//�����˰�f�����ʼΪ��� 
			for(int k=v[i][j-1];k<=v[i+1][j];k++)//�����ı��β���ʽ����һά���Ӷ� 
			{
				if(f[i][j]>f[i][k]+f[k+1][j]+sum[j]-sum[i-1])
				{
					f[i][j]=f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
					v[i][j]=k;
				}
			} 
		}
	}
	cout<<f[1][n];
	return 0;
}
